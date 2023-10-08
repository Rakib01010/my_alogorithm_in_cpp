// #include <bits/stdc++.h>
// using namespace std;

// class Edge
// {
// public:
//     int to;
//     int weight;
//     Edge(int to, int weight) : to(to), weight(weight) {}
// };

// // Dijkstra's algorithm function
// vector<int> dijkstra(int start, vector<vector<Edge>> &graph)
// {
//     int numNodes = graph.size();
//     vector<int> dist(numNodes, INT_MAX); // Initialize distances to infinity
//     dist[start] = 0;                     // Distance from the start node to itself is 0

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push({0, start}); // Push the start node with distance 0

//     while (!pq.empty())
//     {
//         int curNode = pq.top().second;
//         int curDist = pq.top().first;
//         pq.pop();

//         // If we've already processed this node with a shorter distance, skip it
//         if (curDist > dist[curNode])
//         {
//             continue;
//         }

//         for (const Edge &edge : graph[curNode])
//         {
//             int newDist = dist[curNode] + edge.weight;
//             if (newDist < dist[edge.to])
//             {
//                 dist[edge.to] = newDist;
//                 pq.push({newDist, edge.to});
//             }
//         }
//     }

//     return dist;
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

//     int startNode;
//     cin >> startNode;

//     vector<int> shortestDistances = dijkstra(startNode, graph);

//     cout << "Shortest distances from node " << startNode << " to all other nodes:" << endl;
//     for (int i = 0; i < numNodes; ++i)
//     {
//         cout << "Node " << i << ": " << shortestDistances[i] << endl;
//     }

//     return 0;
// }
// input
//  5 7
//  0 1 4
//  0 2 2
//  1 2 5
//  1 3 10
//  2 3 3
//  2 4 2
//  3 4 7
//  0

// Shortest distances from node 0 to all other nodes:
// Node 0: 0
// Node 1: 4
// Node 2: 2
// Node 3: 5
// Node 4: 4

// void
#include <bits/stdc++.h>
using namespace std;

// Define a class to represent edges
class Edge
{
public:
    int to;
    int weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

// Dijkstra's algorithm function
void dijkstra(int start, vector<vector<Edge>> &graph)
{
    int numNodes = graph.size();
    vector<int> dist(numNodes, INT_MAX); // Initialize distances to infinity
    dist[start] = 0;                     // Distance from the start node to itself is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // Push the start node with distance 0

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        // If we've already processed this node with a shorter distance, skip it
        if (curDist > dist[curNode])
        {
            continue;
        }

        for (const Edge &edge : graph[curNode])
        {
            int newDist = dist[curNode] + edge.weight;
            if (newDist < dist[edge.to])
            {
                dist[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < numNodes; ++i)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
}

int main()
{
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<Edge>> graph(numNodes);

    for (int i = 0; i < numEdges; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].emplace_back(to, weight);
    }

    int startNode;
    cin >> startNode;

    dijkstra(startNode, graph);

    return 0;
}
