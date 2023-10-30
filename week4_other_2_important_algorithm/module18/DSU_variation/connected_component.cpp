#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int dsu_find(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = dsu_find(parent[node]);
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        parent[leaderA] = leaderB;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    parent.resize(n + 1, -1);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    // Calculate connected components
    vector<vector<int>> components(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        components[dsu_find(i)].push_back(i);
    }

    // Output connected components
    cout << "Number of Connected Components: " << components.size() - 1 << endl;
    int componentNumber = 1;
    for (int i = 1; i < components.size(); ++i)
    {
        if (!components[i].empty())
        {
            cout << "Connected Component " << componentNumber << ": ";
            for (int node : components[i])
            {
                cout << node << " ";
            }
            cout << endl;
            componentNumber++;
        }
    }

    return 0;
}

// 10 7
// 1 2
// 2 3
// 4 5
// 6 7
// 8 9
// 9 10
// 3 4

// Number of Connected Components: 10
// Connected Component 1: 1 2 3 4 5 
// Connected Component 2: 6 7 
// Connected Component 3: 8 9 10

// number of connected components
//  #include <iostream>
//  #include <vector>
//  using namespace std;

// vector<int> parent;

// int dsu_find(int node) {
//     if (parent[node] == -1) return node;
//     return parent[node] = dsu_find(parent[node]);
// }

// void dsu_union(int a, int b) {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB) {
//         parent[leaderA] = leaderB;
//     }
// }

// int main() {
//     int n, e;
//     cin >> n >> e;
//     parent.resize(n + 1, -1);
//     while (e--) {
//         int a, b;
//         cin >> a >> b;
//         dsu_union(a, b);
//     }

//     // Count connected components
//     int connectedComponents = 0;
//     for (int i = 1; i <= n; ++i) {
//         if (parent[i] == -1) {
//             connectedComponents++;
//         }
//     }

//     cout << "Number of Connected Components: " << connectedComponents << endl;

//     return 0;
// }
