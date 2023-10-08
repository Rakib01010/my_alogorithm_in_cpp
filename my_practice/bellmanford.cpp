#include <bits/stdc++.h>
using namespace std;

// Define a class to represent edges
class Edge
{
public:
    int from;
    int to;
    int weight;
    Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}
};

// Bellman-Ford algorithm function
void bellmanFord(int start, vector<Edge> &edges, int numNodes)
{
    vector<int> dist(numNodes, INT_MAX); // Initialize distances to infinity
    dist[start] = 0;                     // Distance from the start node to itself is 0

    // Relax edges repeatedly to find the shortest paths
    for (int i = 0; i < numNodes - 1; ++i)
    {
        for (const Edge &edge : edges)
        {
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
            {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const Edge &edge : edges)
    {
        if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.weight < dist[edge.to])
        {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }


    for (int i = 0; i < numNodes; ++i)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<Edge> edges;

    for (int i = 0; i < numEdges; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.emplace_back(from, to, weight);
    }

    int startNode;
    cin >> startNode;

    bellmanFord(startNode, edges, numNodes);

    return 0;
}


// 5 7
// 0 1 4
// 0 2 2
// 1 2 5
// 1 3 10
// 2 3 3
// 2 4 2
// 3 4 7
// 0
// output
// Node 0: 0
// Node 1: 4
// Node 2: 2
// Node 3: 5
// Node 4: 4



// 4 4
// 0 1 1
// 1 2 -3  
// 2 3 2 
// 3 1 -1  
// 0 
// output 
// Negative weight cycle detected!