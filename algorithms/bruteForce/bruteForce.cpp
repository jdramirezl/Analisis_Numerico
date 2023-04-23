#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdio.h>
using namespace std;

const long long INF = 1e18;

int n;
vector<vector<long long>> graph;
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
        iter+=1;
        string path;
        long long cost = 0;
        int src = vertices[0];
        
        path+=to_string(src);
        for (int i = 1; i < vertices.size(); i++)
        {
            
            int dest = vertices[i];
           path += "->" + to_string(dest);
            cost += graph[src][dest];
            src = dest;
        }
        cost += graph[src][vertices[0]];
        path += "->" + to_string(vertices[0]);
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

    long long minCost = tsp();

    
    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
