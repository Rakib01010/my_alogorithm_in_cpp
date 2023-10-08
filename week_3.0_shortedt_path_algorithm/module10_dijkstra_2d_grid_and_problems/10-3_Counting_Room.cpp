#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<string> graph;
int visited[N][N];
int n, m; // n number of string
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// way 1
//  typedef pair<int, int> pii;
//  pii parent[N][N];
//  vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
//  int dfs(int i, int j)
//  {
//      // u = i,j
//      if (!isValid(i, j))
//          return 0;
//      if (visited[i][j])
//          return 0;
//      if (graph[i][j] == '#')
//          return 0;
//      visited[i][j] = true;
//      for (auto d : direc)
//      {
//          dfs(i + d.first, j + d.second);
//      }
//  }

// way 2
int dfs(int i, int j)
{
    // u = i,j
    if (!isValid(i, j))
        return 0;
    if (visited[i][j])
        return 0;
    if (graph[i][j] == '#')
        return 0;
    visited[i][j] = true;
    dfs(i, j - 1);//lefy
    dfs(i, j + 1);//right
    dfs(i - 1, j);//up
    dfs(i + 1, j);//down
}
int main()
{

    // int n,m; //n number of string
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        graph.push_back(x);
    }
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == '#') // if wall
                continue;
            if (visited[i][j]) // if visiterd
                continue;

            dfs(i, j);
            ct++;
        }
    }
    cout << ct << endl;
    return 0;
}

// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

/// 3