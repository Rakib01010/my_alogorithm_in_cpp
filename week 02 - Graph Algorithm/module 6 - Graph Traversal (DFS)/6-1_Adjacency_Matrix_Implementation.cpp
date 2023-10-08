#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjmat[N][N];

int main()
{
    int n, m; // node,edge;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // directed
        //adjmat[u][v] = 1; // directed;
        //undirected
        adjmat[u][v] = 1; // undirected
        adjmat[v][u] = 1; // undirected 
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// input
//  4
//  5
//  1 2
//  1 3
//  2 4
//  4 3
//  3 2
//========================//weighted//===========
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// int adjmat[N][N];

// int main()
// {
//     int n, m; // node,edge;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v,w;
//         cin >> u >> v>>w;
//         // directed
//         //adjmat[u][v] = 1; // directed;
//         //undirected
//         adjmat[u][v] = w; // undirected
//         adjmat[v][u] = w; //undirected 
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << adjmat[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Input
// 4
// 5
// 1 2 8
// 1 3 9
// 2 4 11
// 4 3 17
// 3 2 15