
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adjlist[N];
bool visited[N];
void dfs(int u)
{ // section 1: actions just after entering a node u
    visited[u] = true;
    cout << "visiting node u:" << u << endl;
    for (int v : adjlist[u])
    { // section 2:actions before entering a new neighbor/child(for thee)
        if (visited[v])
            continue;
        dfs(v);
        // section 3:actions after exiting a neighbor
    }
    // section 4:actions before exiting node u
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
    cout << "visiting array\n";
    //cheaking visited node
    for (int i = 1; i <= n; i++)
    {
        cout << "Node :" << i << " " << visited[i] << endl;
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
//  10
//  9
//  1 2
//  1 3
//  1 10
//  2 4
//  3 5
//  3 6
//  4 7
//  4 8
//  6 9

// input 2
//  9
//  10
//  1 2
//  2 3
//  3 8
//  1 5
//  5 4
//  5 6
//  6 7
//  7 8
//  8 9

//========================//weighted//===========
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// vector<pair<int,int>>adjlist[N];
// int main()
// {
//     int n, m; // node,edge;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v,w;
//         cin >> u >> v>> w;
//         //directed
//        adjlist[u].push_back({v,w});// directed;
//         //undirected
//         // adjlist[u].push_back({v,w}); // undirected
//         // adjlist[v].push_back({u,w}); // undirected
//     }

//     for(int i=1;i<=n;i++)
//     {
//         cout<<"List"<< i<< ": ";
//         for(auto j:adjlist[i])
//         {
//             cout<<"( "<<j.first<<", "<<j.second<<"),";
//         }
//         cout<<endl;

//     }
//     return 0;
// }
