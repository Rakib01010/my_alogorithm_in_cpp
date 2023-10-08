#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<string> graph;
int visited[N][N];
int level[N][N];
int n, m; // n number of string
typedef pair<int, int> pii;
pii parent[N][N];
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};//down{0, -1} up{0, 1} left{-1, 0} right{1, 0}
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q; //==queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;  //not reached
    while (!q.empty())
    {
        pii upair = q.front(); //==pair<int, int> upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direc)
        {
            int ni = i + d.first;  //new i and newv j
            int nj = j + d.second;
            if (isValid(ni, nj) && !visited[ni][nj] && graph[ni][nj]!='#')
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

    // int n,m; //n number of string
    int si, sj, di, dj; // destination =di ,dj   si= starting sj=starting
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A')
                si = i,sj = j;
            if (x[j] == 'B')
                di = i, dj = j;
        }
        graph.push_back(x);
    }
    bfs(si, sj);            
    if (level[di][dj] != 0) 
    {
        cout << "YES\n";
        cout << level[di][dj] << endl;
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}

// 5 8
// ########
// #.A#...#
// #.#.##B#
// #......#
// ########
//output 9


// 5 8
// ########
// #.A#...#
// #.#.##.#
// #...B..#
// ########
//output 6


// 5 8
// ########
// #.A#...#
// #B#.##.#
// #......#
// ########
//output  2

