#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e19 + 7; 
const int N = 100;
vector<pair<int, long long>> adjList[N + 1];
vector<pair<long long, int>> dist[N + 1];
int n, e;
void floyd_warshall()
{
    // Floyd-Warshall 
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (dist[i][k - 1].first != INF && dist[k][j - 1].first != INF) {
                    dist[i][j - 1].first = min(dist[i][j - 1].first, dist[i][k - 1].first + dist[k][j - 1].first);
                }
            }
        }
    }

}
int main() 
{
    
    cin >> n >> e;
    for (int i = 0; i < e; i++) 
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (i == j) 
            {
                dist[i].push_back({0, j});
            } else {
                dist[i].push_back({INF, j});
            }
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        for ( auto child : adjList[i]) 
        {
            int j = child.first;
            long long w = child.second;
            dist[i][j - 1].first = min(dist[i][j - 1].first, w);
        }
    }

    floyd_warshall();
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int st, en;
        cin >> st >> en;
        if (dist[st][en - 1].first == INF) 
        {
            cout << -1 << endl;
        } 
        else 
        {
            cout << dist[st][en - 1].first << endl;
        }
    }

    return 0;
}





// //***************Floyd-Warshall Algorithm************
// #include <bits/stdc++.h>
// using namespace std;

// const long long INF = 1e18;
// const int N = 100;

// long long adjMatrix[N + 1][N + 1];

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j)
//             {
//                 adjMatrix[i][j] = 0;
//             }
//             else
//             {
//                 adjMatrix[i][j] = INF;
//             }
//         }
//     }

//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         long long w;
//         cin >> u >> v >> w;
//         adjMatrix[u][v] = min(adjMatrix[u][v], w);
//     }

//     // Floyd-Warshall Algorithm
//     for (int k = 1; k <= n; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (adjMatrix[i][k] != INF && adjMatrix[k][j] != INF)
//                 {
//                     adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
//                 }
//             }
//         }
//     }

//     int q;
//     cin >> q;

//     while (q--)
//     {
//         int st, en;
//         cin >> st >> en;
//         if (adjMatrix[st][en] == INF)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << adjMatrix[st][en] << endl;
//         }
//     }

//     return 0;
// }

//***********************DSU******************************
// #include <bits/stdc++.h>
// using namespace std;
// const long long INF = 1e18;
// const int N = 100;

// long long adjMatrix[N + 1][N + 1];
// int parent[N + 1];

// int dsu_find(int node)
// {
//     if (parent[node] == node)
//         return node;
//     return parent[node] = dsu_find(parent[node]);
// }

// void dsu_union(int a, int b)
// {
//     a = dsu_find(a);
//     b = dsu_find(b);
//     if (a != b)
//     {
//         parent[b] = a;
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = i;
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j)
//             {
//                 adjMatrix[i][j] = 0;
//             }
//             else
//             {
//                 adjMatrix[i][j] = INF;
//             }
//         }
//     }

//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         long long w;
//         cin >> u >> v >> w;
//         adjMatrix[u][v] = min(adjMatrix[u][v], w);
//         dsu_union(u, v);
//     }

//     // Floyd-Warshall Algorithm
//     for (int k = 1; k <= n; k++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (adjMatrix[i][k] != INF && adjMatrix[k][j] != INF)
//                 {
//                     if (adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j])
//                     {
//                         adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
//                     }
//                 }
//             }
//         }
//     }

//     int q;
//     cin >> q;

//     while (q--)
//     {
//         int st, en;
//         cin >> st >> en;
        // if (dsu_find(st) != dsu_find(en) || adjMatrix[st][en] == INF)
        // {
        //     cout << -1 << endl;
        // }
        // else
        // {
        //     cout << adjMatrix[st][en] << endl;
        // }
//     }

//     return 0;
// }

//****************dijkstra*********************************
// #include <bits/stdc++.h>
// using namespace std;

// const long long INF = 1e18;
// const int N = 100;

// vector<pair<int, long long>> adj[N + 1];

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         long long w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//     }

//     int q;
//     cin >> q;

//     while (q--)
//     {
//         int st, en;
//         cin >> st >> en;

//         vector<long long> dist(n + 1, INF);
//         dist[st] = 0;

//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//         pq.push({0, st});

//         while (!pq.empty())
//         {
//             int u = pq.top().second;
//             long long d = pq.top().first;
//             pq.pop();

//             if (d > dist[u])
//                 continue;

//             for (pair<int, long long> edge : adj[u])
//             {
//                 int v = edge.first;
//                 long long w = edge.second;

//                 if (dist[u] + w < dist[v])
//                 {
//                     dist[v] = dist[u] + w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         if (dist[en] == INF)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << dist[en] << endl;
//         }
//     }

//     return 0;
// }
