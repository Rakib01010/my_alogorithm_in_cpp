#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u;
    int v;
    long long  int w;
    Edge(int u, int v, long long int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        int a, b; long long int w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}

// 4 4 
// 1 4 10
// 1 2 5
// 3 4 -2
// 2 3 2
// output
// Node 1: 0
// Node 2: 5
// Node 3: 7
// Node 4: 5


///way 2===============
// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> pii;
// const int N = 1e5 + 7;
// const int INF = 1e9 + 7;
// int d[N];
// int n, m;
// vector<pair<pii, int>> list_of_edges;

// void bellman_ford(int s)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         d[i] = INF;
//     }
//     d[s] = 0;
//     for (int i = 0; i < n - 1; i++) // Fix: Use n - 1 iterations
//     {
//         for (auto edge : list_of_edges)
//         {
//             int u = edge.first.first;
//             int v = edge.first.second;
//             int w = edge.second;

//             if (d[u] != INF && d[v] > d[u] + w) // Fix: Use '==' instead of '!='
//             {
//                 d[v] = d[u] + w;
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
//         list_of_edges.push_back({{u, v}, w}); // Fix: Correct the pair initialization
//     }
//     bellman_ford(1);
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "distance od i:" << i;
//         cout << " :" << d[i] << endl;
//         ;
//     }
//     return 0;
// }

