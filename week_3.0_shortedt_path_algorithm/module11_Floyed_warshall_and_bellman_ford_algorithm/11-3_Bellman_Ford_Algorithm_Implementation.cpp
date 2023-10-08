//with list
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
int d[N];
int n, m;
vector<pair<pii, int>> list_of_edges;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;
    for (int i = 0; i < n - 1; i++) // Fix: Use n - 1 iterations
    {
        for (auto edge : list_of_edges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if (d[u] != INF && d[v] > d[u] + w) // Fix: Use '==' instead of '!='
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        list_of_edges.push_back({{u, v}, w}); // Fix: Correct the pair initialization
    }
    bellman_ford(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "distance od i:" << i;
        cout << " :" << d[i] << endl;
        ;
    }
    return 0;
}

// 7
// 10
// 1 2 6
// 1 3 5
// 1 4 5
// 2 5 -1
// 3 2 -2
// 3 5 1
// 4 3 -2
// 4 6 -1
// 5 7 3
// 4 7 3
// distance od i:0 :0
// distance od i:1 :0
// distance od i:2 :1
// distance od i:3 :3
// distance od i:4 :5
// distance od i:5 :0
// distance od i:6 :4
// distance od i:7 :3
//=======================WITHOUT List=========================
// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 1e5 + 7;
// const int INF = 1e9 + 7;
// int d[N];
// int n, m;
// vector<pii> g[N];
// vector<pair<pii, int>> list_of_edges;

// void ballman_ford(int s)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INF;
//     }
//     d[s] = 0;
//     for (int i = 0; i < n; i++)
//     {
//         // all aeges relaxation
//         for (int u = 1; u <= n; u++)
//         {
//             for (pii vpair : g[u])
//             {
//                 int v = vpair.first;
//                 int w = vpair.second;

//                 if (d[u] != INF && d[v] > d[u] + w)
//                     d[v] = d[u] + w;
//             }
//         }
//     }
// }
// int main()
// {

//     cin >> n >> m;
//     while (m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         g[u].push_back({v, w});
//     }
//     ballman_ford(1);
//     for (int i = 1; i <= n; i++)
//     {
// cout << "distance od i:" << i;
// cout << " :" << d[i]<<endl;;
//     }
//     return 0;
// }