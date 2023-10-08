#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adjlist[N];

int main()
{
    int n, m; // node,edge;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //directed
        //adjlist[u].push_back(v);// directed;
        //undirected
        adjlist[u].push_back(v); // undirected
        adjlist[v].push_back(u); // undirected 
    }

    // every node should have list
    for(int i=1;i<=n;i++)
    {  
        cout<<"List"<< i<< ": ";
        for(int j:adjlist[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// input
//  4
//  5
//  1 2
//  1 3
//  2 4
//  4 3
//  3 2
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

// Input
// 4
// 5
// 1 2 8
// 1 3 9
// 2 4 11
// 4 3 17
// 3 2 15