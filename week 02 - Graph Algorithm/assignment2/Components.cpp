#include <bits/stdc++.h>
using namespace std;

const int N = 1001; // Increase the size to accommodate nodes 0 to 1000
vector<int> adj[N];
bool visited[N];
int component_size;

void dfs(int u)
{
    visited[u] = true;
    component_size++;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> component_sizes;

    for (int i = 1; i <= n; ++i)
    {
        visited[i] = false;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            component_size = 0; // counting start
            dfs(i);
            if (component_size > 1)
            {
                component_sizes.push_back(component_size);
            }
        }
    }

    sort(component_sizes.begin(), component_sizes.end());

    for (int size : component_sizes)
    {
        cout << size << " ";
    }

    return 0;
}
