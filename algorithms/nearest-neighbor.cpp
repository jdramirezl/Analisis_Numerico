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

const long long INF = 1e18;

int n;
vector<vector<long long> > dist;
vector<bool> visited;

long long nearestNeighborFromNode(int node, int& start){
    int nextNode = -1;
    long long cost = INF;
    visited[node] = true;
    for(int i = 0; i < n; ++i){
        if(!visited[i] && dist[node][i] < cost){
            nextNode = i;
            cost = dist[node][i];
        }
    }
    if(nextNode == -1){
        return dist[node][start];
    }
    return cost + nearestNeighborFromNode(nextNode, start);
}
long long nearestNeighbor(){
    long long minCircuit = INF;
    for(int i = 0; i < n; ++i){
        minCircuit = min(minCircuit, nearestNeighborFromNode(i, i));
    }
    return minCircuit;
}

int main(){
    
}