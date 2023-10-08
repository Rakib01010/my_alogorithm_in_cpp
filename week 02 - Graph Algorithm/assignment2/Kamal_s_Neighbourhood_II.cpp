#include <bits/stdc++.h>
using namespace std;

const int N = 20; // Maximum number of houses
vector<int> adjlist[N];
bool visited[N];

int one_way = 0;

void dfs(int u)
{
    visited[u] = true;
    one_way++;
    for (int v : adjlist[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m; // node, edge;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }

    int k; // Kamal's house number
    cin >> k;

    dfs(k);

    cout << one_way-1 << endl;

    return 0;
}
