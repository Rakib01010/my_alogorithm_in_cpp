#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
}
//O(n+m)
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, d;
    cin >> s >> d;
    bfs(s); //O(n+m)
    cout << level[d]<<endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "parent of  " << i << " :" << parent[i] << endl;
    // }

    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(),path.end());
    cout<<"path :";
    for(int node :path)
    {
        cout<<node<<" ";
    }

    return 0;
}

// input
//  12
//  11
//  1 2
//  1 3
//  1 10
//  2 4
//  2 5
//  3 9
//  5 6
//  5 7
//  7 8
//  10 11
//  10 12
