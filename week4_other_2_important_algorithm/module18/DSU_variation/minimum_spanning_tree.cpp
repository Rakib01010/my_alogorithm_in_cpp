#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> parent;

int dsu_find(int node) {
    if (parent[node] == -1) return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB) {
        parent[leaderA] = leaderB;
    }
}

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> edges(e);
    parent.resize(n + 1, -1);

    for (int i = 0; i < e; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    int totalWeight = 0;
    vector<Edge> mstEdges; // Store edges of MST

    for (Edge edge : edges) {
        if (dsu_find(edge.u) != dsu_find(edge.v)) {
            dsu_union(edge.u, edge.v);
            totalWeight += edge.weight;
            mstEdges.push_back(edge);
        }
    }

    cout << "Minimum Spanning Tree Weight: " << totalWeight << endl;
    cout << "Minimum Spanning Tree Edges:\n";
    for (const auto& edge : mstEdges) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}



// 4 5
// 0 1 10
// 0 2 6
// 0 3 5 
// 1 3 15
// 2 3 4


// Minimum Spanning Tree Weight: 19
// Minimum Spanning Tree Edges:
// 2 - 3 : 4
// 0 - 3 : 5
// 0 - 1 : 10