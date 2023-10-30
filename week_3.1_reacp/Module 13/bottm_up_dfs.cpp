#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool vis[N];
vector<int> v[N];

void dfs(int start) {
    stack<int> stk;
    stk.push(start);
    vis[start] = true;

    while (!stk.empty()) {
        int s = stk.top();
        stk.pop();
        cout << s << endl;

        for (int i = 0; i < v[s].size(); i++) {
            int child = v[s][i];
            if (!vis[child]) {
                stk.push(child);
                vis[child] = true;
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << vis[i] << endl;
    }

    return 0;
}

// i
// 5 5
// 1 2
// 1 3
// 2 4
// 3 5
// 4 5
// o
// 1
// 3
// 5
// 4
// 2
// Node 1: True
// Node 2: True
// Node 3: True
// Node 4: True
// Node 5: True
