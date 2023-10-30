#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int dsu_find(int node) {
    if (parent[node] == -1) return node;
    return parent[node] = dsu_find(parent[node]);
}

bool dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA == leaderB) return true;
    parent[leaderA] = leaderB;
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    parent.resize(n + 1, -1);
    bool hasCycle = false;
    while (e--) {
        int a, b;
        cin >> a >> b;
        if (dsu_union(a, b)) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) cout << "Graph contains a cycle.";
    else cout << "Graph does not contain a cycle.";

    return 0;
}



// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 1

// Graph contains a cycle.