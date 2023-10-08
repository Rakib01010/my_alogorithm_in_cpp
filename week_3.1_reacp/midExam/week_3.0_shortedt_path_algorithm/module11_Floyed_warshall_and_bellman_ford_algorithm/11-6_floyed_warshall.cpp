#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int d[N][N];
int n, m;

void dist_initialize() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                d[i][j] = INF;
        }
    }
}

void print_matrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF)
                cout << "X ";
            else
                cout << d[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    dist_initialize();

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        // d[v][u]=w;
    }

    cout << "Initial matrix:" << endl;
    print_matrix();

    // Floyd-Warshall
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << "After Floyd-Warshall:" << endl;
    print_matrix();

    return 0;
}


// 5
// 7
// 1 2 2
// 1 3 6
// 2 3 1
// 3 4 4
// 4 2 6
// 2 5 3
// 5 4 9

// output
// Initial matrix:
// 0 2 6 X X 
// X 0 1 X 3 
// X X 0 4 X 
// X 6 X 0 X 
// X X X 9 0 
// After Floyd-Warshall:
// 0 2 3 7 5 
// X 0 1 5 3 
// X 10 0 4 13 
// X 6 7 0 9 
// X 15 16 9 0 