#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> graph;
int niterMax=1e6;
int tsp()
{
    vector<int> vertices;
    for (int i = 0; i < n; i++)
    {
        vertices.push_back(i);
    }

    int minCost = INF;
    int iter=0;
    do
    {
        iter+=1;
        string path;
        int cost = 0;
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
        cout << path << " cost = " << cost << endl;
    } while (next_permutation(vertices.begin(), vertices.end()) && iter<niterMax);

    return minCost;
};

int main(int argc, char const *argv[])
{
   
    
    
    ifstream infile("input.txt");

   
    infile >> n;

   
    graph.resize(n, vector<int>(n));

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> graph[i][j];
        }
    }

    
    infile.close();

    
    int minCost = tsp();

    
    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
