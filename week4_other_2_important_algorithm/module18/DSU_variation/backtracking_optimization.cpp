#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> parentCopy;

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

bool isSafe(vector<vector<int>>& graph, int v, int color, int c) {
    for (int i = 0; i < graph[v].size(); ++i) {
        if (graph[v][i] && parentCopy[i] == color) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, int v) {
    if (v == graph.size()) return true;

    for (int c = 1; c <= m; ++c) {
        if (isSafe(graph, v, c, v)) {
            parentCopy[v] = c;
            if (graphColoringUtil(graph, m, v + 1)) return true;
            parentCopy[v] = 0;
        }
    }

    return false;
}

void graphColoring(vector<vector<int>>& graph, int m) {
    parentCopy = parent;
    if (graphColoringUtil(graph, m, 0)) {
        cout << "Graph can be colored using " << m << " colors.\n";
    } else {
        cout << "Graph cannot be colored using " << m << " colors.\n";
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    parent.resize(n, -1);
    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Input edges
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
        dsu_union(u, v);
    }

    int m; // Number of colors available
    cin >> m;
    graphColoring(graph, m);

    return 0;
}


// Input:
// 4 5
// 0 1
// 0 2
// 0 3
// 1 3
// 2 3
// 3

// Explanation:
// - The graph has 4 vertices (0, 1, 2, 3) and 5 edges connecting these vertices as specified.
// - The edges are: (0, 1), (0, 2), (0, 3), (1, 3), and (2, 3).
// - The number of colors available is 3.

// Output:
// Graph can be colored using 3 colors.