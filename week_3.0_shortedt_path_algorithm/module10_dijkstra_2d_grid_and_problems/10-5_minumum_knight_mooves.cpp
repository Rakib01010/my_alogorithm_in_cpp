// knight= horse
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int visited[N][N];
int level[N][N];
int n, m; // n number of string
typedef pair<int, int> pii;
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1},{-2,1},{-2,-1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0; // not reached
    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direc)
        {
            int ni = i + d.first; // new i and newv j
            int nj = j + d.second;
            if (isValid(ni, nj) && !visited[ni][nj])
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}
void reset_level_vis()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
int main()
{

    int si, sj, di, dj;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';

        di = y[0] - 'a';
        dj = y[1] - '1';
        // cout << "( " << si << " " << sj << ")";
        // cout << "( " << di << " " << dj << ")\n";
        bfs(si, sj);
        cout << level[di][dj] << endl;
        reset_level_vis();
    }

    return 0;
}

// 3
// a1 h8
// a1 c2
// h8 c3

//6 1 4