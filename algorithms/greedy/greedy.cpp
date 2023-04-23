#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;

#define ll long long

struct edge{
    ll u, v, w;
    edge(ll _u, ll _v, ll _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge &other) const {
        return w < other.w;
    }
};

const ll MAXN = 1e5 + 5;
vector<ll> parent, degree;
vector<edge> edges;
ll n, m;

ll find(ll u) {
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

bool merge(ll u, ll v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    parent[u] = v;
    return true;
}

ll greedy(vector<vector<ll> > &graph) {
    vector<edge> path;
    ll cost = 0;

    for (auto &v : graph) {
        for (auto &u : v) {
            edges.push_back(edge(v[0], u, 0));
        }
    }

    n = graph.size();
    m = edges.size();

    parent = vector<ll>(n + 1);
    degree = vector<ll>(n + 1);
    edges = vector<edge>(m);

    sort(edges.begin(), edges.end());

    for(ll i = 0; i <= n; i++){
        parent[i] = i;
    }

    for (ll i = 0; i < m; i++) {
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


int main(ll argc, char** argv){
    freopen(argv[1], "r", stdin);
    cin >> n;

    // Getting matrix
    vector<vector<ll>> matrix(n, vector<ll>(n));
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }

    // To graph
    vector<vector<ll>> graph(n);
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            if(matrix[i][j] == 1){
                graph[i].push_back(j);
            }
        }
    }
    auto start_time = std::chrono::high_resolution_clock::now();
    ll ans = greedy(graph);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<double> >(end_time - start_time);
    cout << ans << '\n' << "Time: " << elapsed_time.count() << '\n';
}