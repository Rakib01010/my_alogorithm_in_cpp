#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];

void bfs(int s, int d)
{
    queue<int> q;
    vector<int> distance_of_nodes(N, -1);
    vector<bool> visited(N, false);

    q.push(s);
    visited[s] = true;
    distance_of_nodes[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                distance_of_nodes[v] = distance_of_nodes[u] + 1;
            }
        }
    }

    cout << distance_of_nodes[d] << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int s, d;
        cin >> s >> d;
        bfs(s, d);
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5;
// vector<int> adj[N];
// bool visited[N];

// void bfs(int s, int d)
// {

//     queue<int> q;
//     vector<int> distance_of_nodes(N,-1);//giving default value -1

//     q.push(s);
//     visited[s] = true;
//     distance_of_nodes[s] = 0;

//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();

//         for (int v : adj[u])
//         {
//             if (!visited[v])
//             {
//                 visited[v] = true;
//                 q.push(v);
//                 distance_of_nodes[v] = distance_of_nodes[u] + 1;
//             }
//         }
//     }

//     cout << distance_of_nodes[d] << endl;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 1; i <= m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     int q;
//     cin >> q;

//     for (int i = 0; i < q; i++)
//     {

//         int s, d;
//         cin >> s >> d;
//         bfs(s, d);
//          for (int j = 0; j <= q; j++)
//         {
//             visited[j] = false; //making all the visited array false
//         }
//     }

//     return 0;
// }
