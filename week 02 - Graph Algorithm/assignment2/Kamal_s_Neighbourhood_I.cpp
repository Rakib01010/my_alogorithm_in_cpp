#include <bits/stdc++.h>
using namespace std;
int nodes;
const int N = 20; // Max  houses
vector<int> adjlist[N];
bool visited[N];

void dfs(int u, int l)
{
    visited[u] = true;
    if (l == 0)
    {
        nodes++;
        return;
    }
    for (int v : adjlist[u])
    {
        if (!visited[v])
        {
            dfs(v, l - 1);
        }
    }
}

int main()
{
    int n, m; // node, edge;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // undirected
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    int k; // Kamal's house number
    cin >> k;

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    dfs(k, 1); // Print first level neighbors if kamal
    cout << nodes;
    return 0;
}
