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
#include <chrono>
#include <unordered_set>

using namespace std;

#define ll long long

struct edge{
    ll u, v, w;
    edge(ll _u, ll _v, ll _w) : u(_u), v(_v), w(_w) {}
    edge() : u(0), v(0), w(0) {}
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
    // parent[u] = v;
    return true;
}

ll greedy(vector<vector<ll> > &graph) {
    ll cost = 0;
    edges = vector<edge>(m);

    unordered_set<ll> used;

    for (ll i = 0; i < graph.size(); i++) {
        for (ll j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == 0) continue;
            if (i == j) continue;
            edges.push_back(edge(i, j, graph[i][j]));
        }
    }

    n = graph.size();
    m = edges.size();

    parent = vector<ll>(n + 1);
    degree = vector<ll>(n + 1, 0);

    sort(edges.begin(), edges.end());

    for(ll i = 0; i <= n; i++){
        parent[i] = i;
    }

    vector<edge> path;
    // cout << "M: " << m << '\n';
    for (ll i = 0; i < m; i++) {
        if (path.size() == n) break;    

        edge e = edges[i];
        // cout << i << "| Edge: " << e.u << " " << e.v << " " << e.w << '\n';
        // if (used.count(e.u)) continue;
        if (!merge(e.u, e.v)) continue;
        // cout << "Passed! 1\n";
        // cout << "Merge: " << e.u << " " << e.v << '\n';
        // cout << "Degree of " << e.u << ": " << degree[e.u] << '\n';
        // cout << "Degree of " << e.v << ": " << degree[e.v] << '\n';
        // cout << (degree[e.u] < 2) << " " << (degree[e.v] < 2) << '\n';
        if ((degree[e.u] < 2) && (degree[e.v] < 2)) {
            // cout << "Passed! 2" << '\n';
            // used.insert(e.u);
            parent[e.u] = e.v;
            degree[e.u]++;
            degree[e.v]++;
            cost += e.w;
            path.push_back(e);
        }
        // // print path 
        // cout << "Path::\n";
        // for(ll i = 0; i < path.size(); ++i){
        //     cout << path[i].u << " " << path[i].v << ", ";
        // }
        // cout << '\n';
    }

    // // print parent
    // for(ll i = 0; i < n; ++i){
    //     cout << i << ":" << parent[i] << ", ";
    // }
    // cout << '\n';

    // cout << "Path: " << path.size() << '\n';
    // cout << "Cost: " << cost << '\n';
    // cout << "N: " << n << '\n';
    // // print path 
        // cout << "Path::\n";
        // for(ll i = 0; i < path.size(); ++i){
        //     cout << path[i].u << " " << path[i].v << ", ";
        // }
        // cout << '\n';
    return path.size() < n - 1 ? -1 : cost;
}


int main(int argc, char** argv){
    freopen(argv[1], "r", stdin);
    // freopen("../../adjecency_graph/burma14.tsp", "r", stdin);
    cin >> n;
    // cout << "Init N: " << n << '\n';

    // Getting matrix
    vector<vector<ll>> matrix(n, vector<ll>(n));
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            cin >> matrix[i][j];
        }
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    ll ans = greedy(matrix);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<double> >(end_time - start_time);
    cout << ans << '\n' << "Time: " << elapsed_time.count() << '\n';
}