#include <bits/stdc++.h>
using namespace std;
int parent[1000];
int parentSize[1000];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    cout << dsu_find(4);
    return 0;
}
// 7 4
// 1 2
// 2 3
// 4 5
// 6 5

// directed graph
// #include <bits/stdc++.h>
// using namespace std;

// struct Edge {
//     int u, v, weight;
//     Edge(int a, int b, int w) : u(a), v(b), weight(w) {}
// };

// int parent[1000];
// int parentSize[1000];

// void dsu_set(int n) {
//     for (int i = 1; i <= n; i++) {
//         parent[i] = -1;
//         parentSize[i] = 1;
//     }
// }

// int dsu_find(int node) {
//     while (parent[node] != -1) {
//         node = parent[node];
//     }
//     return node;
// }

// void dsu_union(int a, int b) {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB) {
//         if (parentSize[leaderA] > parentSize[leaderB]) {
//             // A leader
//             parent[leaderB] = leaderA;
//             parentSize[leaderA] += parentSize[leaderB];
//         } else {
//             parent[leaderA] = leaderB;
//             parentSize[leaderB] += parentSize[leaderA];
//         }
//     }
// }

// int main() {
//     int n, e;
//     cin >> n >> e;
//     dsu_set(n);
    
//     vector<Edge> edges;

//     while (e--) {
//         int a, b, weight;
//         cin >> a >> b >> weight;
//         edges.push_back(Edge(a, b, weight));
//     }

//     // Sort edges by weight in ascending order
//     sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
//         return a.weight < b.weight;
//     });

//     int totalWeight = 0;

//     for (Edge& edge : edges) {
//         if (dsu_find(edge.u) != dsu_find(edge.v)) {
//             dsu_union(edge.u, edge.v);
//             totalWeight += edge.weight;
//         }
//     }

//     cout << "Minimum Spanning Tree Weight: " << totalWeight << endl;

//     return 0;
// }

// 4 7
// 1 2 10
// 2 3 5
// 3 4 2
// 4 2 3
// 3 1 7
// 2 1 1
// 1 4 4