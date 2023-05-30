#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdio.h>
using namespace std;

const long long INF = 1e18;

int n;
vector<vector<long long> > graph;
int niterMax=1e6;
long long tsp()
{
    vector<long long> vertices;
    for (int i = 0; i < n; i++)
    {
        vertices.push_back(i);
    }

    long long minCost = INF;
    int iter=0;
    do
    {
        iter++;
        long long cost = 0;
        int src = vertices[0];
        
        for (int i = 1; i < vertices.size(); i++)
        {
            
            int dest = vertices[i];
            cost += graph[src][dest];
            src = dest;
        }
        cost += graph[src][vertices[0]];
        
        if (minCost > cost)
            minCost = cost;
        
    } while (next_permutation(vertices.begin(), vertices.end()) && iter<niterMax);

    return minCost;
};

int main(int argc, char const *argv[])
{
   
    
    
    freopen(argv[1], "r", stdin);
    cin >> n;
    graph.resize(n, vector<long long>(n));
    int node;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    

    
    auto start_time = std::chrono::high_resolution_clock::now();
    long long ans = tsp();
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::duration<double> >(end_time - start_time);
    cout << ans << '\n' << "Time: " << elapsed_time.count() << '\n';

    return 0;
}
