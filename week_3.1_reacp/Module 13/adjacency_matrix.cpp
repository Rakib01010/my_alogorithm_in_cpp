#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = 0;
            if (i == j)
                adj[i][j] = 1;//self connected
        }
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 4 5
// 1 2
// 1 3
// 2 3
// 2 4
// 3 4

// 1 0 0 0 0 
// 0 1 1 1 0 
// 0 1 1 1 1 
// 0 1 1 1 1 
// 0 0 1 1 1