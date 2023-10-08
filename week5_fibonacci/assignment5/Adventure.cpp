#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int knapsack(int n, int s, int v[], int w[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        return dp[n][s] = max(op1, op2);
    }
    else
    {
        return dp[n][s] = knapsack(n - 1, s, v, w);
    }
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        int n, s;
        cin >> n >> s;
        int v[n], w[n];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << knapsack(n, s, v, w) << endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int knapsack(int n, int s, int v[], int w[])
// {
//     int dp[n + 1][s + 1];

//     // Initialize the DP array
//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= s; j++) {
//             if (i == 0 || j == 0)
//                 dp[i][j] = 0;
//             else
//                 dp[i][j] = -1;
//         }
//     }

//     // Fill the DP array
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= s; j++) {
//             if (w[i - 1] <= j) {
//                 int op1 = v[i - 1] + dp[i - 1][j - w[i - 1]];
//                 int op2 = dp[i - 1][j];
//                 dp[i][j] = max(op1, op2);
//             } else {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     return dp[n][s];
// }

// int main()
// {
//     int cas;
//     cin >> cas;
//     while (cas--) {
//         int n, s;
//         cin >> n >> s;
//         int v[n], w[n];
//         for (int i = 0; i < n; i++) {
//             cin >> w[i];
//         }
//         for (int i = 0; i < n; i++) {
//             cin >> v[i];
//         }

//         cout << knapsack(n, s, v, w) << endl;
//     }
//     return 0;
// }
