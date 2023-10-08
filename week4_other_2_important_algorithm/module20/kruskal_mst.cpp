
#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{1 5 2
8 6 2
    return a.w < b.w;
}
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        dsu_union(a, b);
    }
    for (Edge val : ans)
    {
        cout << val.a << " " << val.b << " " << val.w << endl;
    }
    return 0;
}

////==================================
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// int parent[N];
// int parentSize[N];

// void dsu_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1;
//         parentSize[i] = 1;
//     }
// }

// int dsu_find(int node)
// {
//     while (parent[node] != -1)
//     {
//         node = parent[node];
//     }
//     return node;
// }

// void dsu_union(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         if (parentSize[leaderA] > parentSize[leaderB])
//         {
//             // A leader
//             parent[leaderB] = leaderA;
//             parentSize[leaderA] += parentSize[leaderB];
//         }
//         else
//         {
//             parent[leaderA] = leaderB;
//             parentSize[leaderB] += parentSize[leaderA];
//         }
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     dsu_set(n);

//     while (e--)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         pq.push({w, a * N + b});
//     }

//     vector<pair<int, pair<int, int>>> ans;

//     while (!pq.empty())
//     {
//         pair<int, int> val = pq.top();
//         pq.pop();
//         int w = val.first;
//         int combined = val.second;
//         int a = combined / N;
//         int b = combined % N;

//         int leaderA = dsu_find(a);
//         int leaderB = dsu_find(b);

//         if (leaderA == leaderB)
//         {
//             continue;
//         }

//         ans.push_back({w, {a, b}});
//         dsu_union(a, b);
//     }

//     for (pair<int, pair<int, int>> val : ans)
//     {
//         int a = val.second.first;
//         int b = val.second.second;
//         int w = val.first;
//         cout << a << " " << b << " " << w << endl;
//     }

//     return 0;
// }


// input
// 8 11
// 1 5 2
// 1 2 4
// 1 4 10
// 5 4 5
// 2 4 8
// 2 3 18
// 3 4 11
// 4 8 9
// 4 7 11
// 7 6 1
// 8 6 2

// output
// 7 6 1
// 1 5 2
// 8 6 2
// 1 2 4
// 5 4 5
// 4 8 9
// 3 4 11