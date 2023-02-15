from math import inf

def nearestNeighborFromNode(node, start):
    nextNode = -1
    cost = inf
    visited[node] = True
    for i in range(n):
        if(not visited[i] and dist[node][i] < cost):
            nextNode = i
            cost = dist[node][i]
    if(nextNode == -1):
        return dist[node][start]
    return cost + nearestNeighborFromNode(nextNode, start)

def nearestNeighbor():
    minCircuit = inf
    for i in range(n):
        minCircuit = min(minCircuit, nearestNeighborFromNode(i, i))
    return minCircuit

n = input()
dist = [[inf for _ in range(n - 1)] for __ in range(n)]
visited = [False for _ in range(n)]