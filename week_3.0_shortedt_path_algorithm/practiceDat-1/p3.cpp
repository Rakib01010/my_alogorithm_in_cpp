#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<string> graph;
int visited[N][N];
int level[N][N];
int n, m;
typedef pair<int, int> pii;
pii parent[N][N];
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
// int dfs(int sourse)
// {
//     visited[sourse] = true;
//     for (int v : graph[sourse])
//     {
//         if (visited[v])
//             continue;
//         dfs(v);
//     }
// }

int bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pii upair = q.front();
        q.pop();
        int i = upair.first;
        int j = upair.second;

        for (auto d : direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}
int main()
{

    int si, sj, di, dj;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
                si = i, sj = j;
            if (x[j] == 'e')
                di = i, dj = j;
        }
        graph.push_back(x);
    }
    bfs(si, sj);
    cout << level[di][dj] << endl;
    return 0;
}