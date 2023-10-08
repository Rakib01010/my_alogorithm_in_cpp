#include <bits/stdc++.h>
using namespace std;

// Define the number of nodes in the graph
const int numNodes = 6; // Adjust this based on your graph size

// Define an adjacency list representation of the graph using arrays
vector<int> graph[numNodes];

// BFS function
void bfs(int start)
{
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " "; // Process the node (e.g., print it)

        for (const auto &neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    // User input
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;
    for (int i = 0; i < numEdges; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1); // For undirected graph
    }

    int startNode;
    cin >> startNode;
    bfs(startNode);

    // giving input
    // graph[0] = {1, 2};
    // graph[1] = {0, 3, 4};
    // graph[2] = {0, 5};
    // graph[3] = {1};
    // graph[4] = {1, 5};
    // graph[5] = {2, 4};

    // cout << "BFS traversal starting from node 0:" << endl;
    // bfs(0);


    return 0;
}
//input
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
// //output
// 0 1 2 3 4 5 6 


