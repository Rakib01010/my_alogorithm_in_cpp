#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 1009;

class Edge
{
public:
    int source, destination;
    long long int weight;

    Edge(int s, int d, long long int w)
    {
        this->source = s;
        this->destination = d;
        this->weight = w;
    }
};

vector<Edge> parent;
long long int dist[N]; // Change the data type to long long int

void make_all_inf(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INF;
    }
}

bool bellman_ford(int n, int s)
{
    make_all_inf(n);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto child : parent)
        {
            int u = .source;
            int v = .destination;
            long long int w = .weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto  : parent)
    {
        int u = .source;
        int v = .destination;
        long long int w = .weight;
        if (dist[u] != INF && dist[u] + w < dist[v])
            return true;
    }

    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        long long int w;
        cin >> u >> v >> w;
        parent.push_back(Edge(u, v, w));
    }
    int s, t;
    cin >> s >> t;

    if (bellman_ford(n, s))
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        for (int i = 0; i < t; ++i)
        {
            int tar;
            cin >> tar;

            if (dist[tar] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dist[tar] << endl;
            }
        }
    }
    return 0;
}


// #include <iostream>

// const int INF = 1e9;
// const int MAXN = 1005;
// const int MAXE = 2005;

// class Edge {
// public:
//     int source, destination, weight;

//     Edge(int s, int d, int w) {
//         this->source = s;
//         this->destination = d;
//         this->weight = w;
//     }
// };

// Edge* edges[MAXE]; // Declare an array of pointers to Edge objects
// int dist[MAXN];

// void bellmanFord(int N, int E, int S) {
//     for (int i = 1; i <= N; ++i) {
//         dist[i] = INF;
//     }
//     dist[S] = 0;

//     for (int i = 1; i <= N - 1; ++i) {
//         for (int j = 0; j < E; ++j) {
//             int u = edges[j]->source;
//             int v = edges[j]->destination;
//             int w = edges[j]->weight;
//             if (dist[u] != INF && dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;
//             }
//         }
//     }
// }

// int main() {
//     int N, E;
//     std::cin >> N >> E;

//     for (int i = 0; i < E; ++i) {
//         int src, dest, weight;
//         std::cin >> src >> dest >> weight;
//         edges[i] = new Edge(src, dest, weight); // Create new Edge objects and store pointers
//     }

//     int S, T;
//     std::cin >> S >> T;

//     bellmanFord(N, E, S);

//     for (int i = 0; i < T; ++i) {
//         int D;
//         std::cin >> D;

//         if (dist[D] == INF) {
//             std::cout << "Not Possible" << std::endl;
//         } else {
//             std::cout << dist[D] << std::endl;
//         }
//     }

//     // Deallocate memory for dynamically created Edge objects
//     for (int i = 0; i < E; ++i) {
//         delete edges[i];
//     }

//     return 0;
// }
