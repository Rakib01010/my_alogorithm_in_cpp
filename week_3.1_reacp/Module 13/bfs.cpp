#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dis[N];
int dis1[N];
bool vis[N];
bool vis1[N];
vector<int> v[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            if (vis[child] == false)
            {
                q.push(child);
                dis[child] = dis[parent] + 1;
                vis[child] = true;
            }
        }
    }
}
void bfs1(int src)
{
    queue<int> q;
    q.push(src);
    vis1[src] = true;
    dis1[src] = 0;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for (int i = 0; i < v[parent].size(); i++)
        {
            int child = v[parent][i];
            if (vis1[child] == false)
            {
                q.push(child);
                dis1[child] = dis1[parent] + 1;
                vis1[child] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //bfs(0);
    bfs1(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
      cout << "Node "  << ": " << dis[0] << endl;
    return 0;
}