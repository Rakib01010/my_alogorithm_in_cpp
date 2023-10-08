#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100; // Maximum number of nodes
int graph[MAX_NODES][MAX_NODES];

// Define a class to represent edges
class Edge
{
public:
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

// Floyd-Warshall algorithm function
void floydWarshall( int numNodes)
{
    // Initialize the distance matrix with initial graph values
    int dist[MAX_NODES][MAX_NODES];
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm to find shortest paths
    for (int k = 0; k < numNodes; ++k)
    {
        for (int i = 0; i < numNodes; ++i)
        {
            for (int j = 0; j < numNodes; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between nodes:" << endl;
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "INF\t";
            }
            else
            {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;


    // Initialize the graph with INF (infinity) values
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            graph[i][j] = INT_MAX;
        }
    }

    // Input the edges and their weights
    for (int i = 0; i < numEdges; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from][to] = weight;
    }

    // Call the Floyd-Warshall algorithm function
    floydWarshall( numNodes);

    return 0;
}




// #include <iostream>
// #include <vector>

// using namespace std;

// // Define a class to represent edges
// class Edge
// {
// public:
//     int to;
//     int weight;
//     Edge(int to, int weight) : to(to), weight(weight) {}
// };

// const int INF = 1e9; // Infinity value for unreachable nodes

// void floydWarshall(int numNodes, vector<vector<Edge>> &graph)
// {
//     vector<vector<int>> dist(numNodes, vector<int>(numNodes, INF));

//     // Initialize distances based on direct edges
//     for (int i = 0; i < numNodes; ++i)
//     {
//         for (const Edge &edge : graph[i])
//         {
//             dist[i][edge.to] = edge.weight;
//         }
//     }

//     // Floyd-Warshall algorithm
//     for (int k = 0; k < numNodes; ++k)
//     {
//         for (int i = 0; i < numNodes; ++i)
//         {
//             for (int j = 0; j < numNodes; ++j)
//             {
//                 if (dist[i][k] != INF && dist[k][j] != INF)
//                 {
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }

//     // Print the shortest distances
//     cout << "Shortest distances between all pairs of nodes:" << endl;
//     for (int i = 0; i < numNodes; ++i)
//     {
//         for (int j = 0; j < numNodes; ++j)
//         {
//             if (dist[i][j] == INF)
//             {
//                 cout << "INF\t";
//             }
//             else
//             {
//                 cout << dist[i][j] << "\t";
//             }
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     int numNodes, numEdges;
//     cin >> numNodes >> numEdges;

//     vector<vector<Edge>> graph(numNodes);

//     for (int i = 0; i < numEdges; ++i)
//     {
//         int from, to, weight;
//         cin >> from >> to >> weight;
//         graph[from].emplace_back(to, weight);
//     }

//     floydWarshall(numNodes, graph);

//     return 0;
// }

// 5 9
// 0 1 3
// 0 2 8
// 0 4 -4
// 1 3 1
// 1 4 7
// 2 1 4
// 3 0 2
// 3 2 -5
// 4 3 6

// output_iterator_tag
// Shortest distances between all pairs of nodes:
// 4	1	-3	2	-4
// 3	0	-4	1	-1
// 7	4	0	5	3
// 2	-1	-5	0	-2
// 8	5	1	6	4

