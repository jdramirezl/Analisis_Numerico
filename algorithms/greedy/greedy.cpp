#include <bits/stdc++.h>
using namespace std;


struct edge{
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge &other) const {
        return w < other.w;
    }
};

const int MAXN = 1e5 + 5;
vector<int> parent, degree;
vector<edge> edges;
int n, m;

int find(int u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    parent[u] = v;
    return true;
}

int greedy(vector<vector<int>> &graph) {
    vector<edge> path;
    int cost = 0;

    for (auto &v : graph) {
        for (auto &u : v) {
            edges.push_back(edge(v[0], u, 0));
        }
    }

    n = graph.size();
    m = edges.size();

    parent = vector<int>(n + 1);
    degree = vector<int>(n + 1);
    edges = vector<edge>(m);

    sort(edges.begin(), edges.end());

    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        if (path.size() == n) break;

        edge e = edges[i];

        if (!merge(e.u, e.v)) continue;

        if (degree[e.u] < 2 && degree[e.v] < 2) {
            degree[e.u]++;
            degree[e.v]++;
            cost += e.w;
            path.push_back(e);
        }
    }

    return path.size() < n ? -1 : cost;
}
