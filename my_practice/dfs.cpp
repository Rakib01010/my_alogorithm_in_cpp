#include <bits/stdc++.h>
using namespace std;

// Define the number of nodes in the graph
const int numNodes = 6; // Adjust this based on your graph size

// Define an adjacency list representation of the graph using arrays
vector<int> graph[numNodes];

// DFS function
void dfs(int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " "; // Process the node (e.g., print it)

    for ( auto neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited);
        }
    }
}

int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);  // For undirected graph
    }

    int startNode;
    cin >> startNode;

    vector<bool> visited(numNodes, false);
    dfs(startNode, visited);
    // Add edges to the graph (using 0-based indices)
    // graph[0] = {1, 2};
    // graph[1] = {0, 3, 4};
    // graph[2] = {0, 5};
    // graph[3] = {1};
    // graph[4] = {1, 5};
    // graph[5] = {2, 4};

    // vector<bool> visited(numNodes, false);

    // cout << "DFS traversal starting from node 0:" << endl;
    // dfs(0, visited);
    
    return 0;
}
// input
// 7 8
// 0 1
// 0 2
// 1 3
// 1 4
// 2 5
// 3 4
// 4 5
// 5 6
// 0
// output
// 0 1 3 4 5 2 6 
