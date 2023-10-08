
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjlist[N];
bool visited[N];
int depth[N];  // parent to childern
int height[N]; // children to parent

void dfs(int u)
{
    visited[u] = true;
    for (int v : adjlist[u])
    {
        if (visited[v] == true)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        // now we can determine the height of u
        // long
        //  if(height[v]+1 > height[u])
        //      height[u]=height[v]+1;

        // shortcut
        height[u] = max(height[u], height[v] + 1);
    }
}
int main()
{
    int n, m; // node,edge;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // directed
        // adjlist[u].push_back(v);// directed;
        // undirected
        adjlist[u].push_back(v); // undirected
        adjlist[v].push_back(u); // undirected
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Deth of node " << i << " :" << depth[i] << endl;
    }
    cout << "................................." << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "height of node " << i << " :" << height[i] << endl;
    }
    // printing all
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "node" << i << ": ";
    //     for (int j : adjlist[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
// input 1
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
//  6 8
//  10 11
//  10 12