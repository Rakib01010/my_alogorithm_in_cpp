#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s, int l)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
        }
    }

    vector<int> shops_at_that_Level;
    for (int i = 0; i < N; i++)
    {
        if (visited[i]) // if parent is true
        {
            if (level[i] == l)
            {
                shops_at_that_Level.push_back(i);
            }
        }
    }

    if (shops_at_that_Level.empty())
    {
        cout << -1;
    }
    else
    {
        for (int shop : shops_at_that_Level)
        {
            cout << shop << " ";
        }
    }

    cout << endl;
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

    int kamal;
    cin >> kamal;

    bfs(0, kamal);

    return 0;
}
