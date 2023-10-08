// dfs or bfs
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool isCycleExiest = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
            return true;
        // isCycleExiest |= dfs(v,u);
        isCycleExiest = isCycleExiest | dfs(v, u);
        //***dfs(v,u) will return true of false
    }
    return isCycleExiest;
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
    // for example 12
    //  if (dfs(1))
    //  {
    //      cout << "cycle detected\n";
    //  }
    //  else
    //  {
    //      cout << " no cycle detected\n";
    //  }

    
    // for example 3
    //  to file another component cycle
    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isCycle |= dfs(i);
    }
    if (isCycle)
         cout << "cycle detected\n";
    
    else
        cout << " nocycle detected\n";
    
    return 0;
}

// input1
// 5
// 5
// 1 2
// 2 3
// 3 5
// 5 4
// 4 2
// input 2
// 5
// 4
// 1 2
// 2 3
// 3 5
// 5 4
// input 3
//  8
//  7
//  1 2
//  2 3
//  3 5
//  2 4
//  6 7
//  6 8
//  7 8