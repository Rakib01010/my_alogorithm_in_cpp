// #top down
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int max_sum = 1000;
int dp[N + 1][max_sum + 1];

bool subset_sum(int n, int a[], int s)
{
    if (s == 0)
        return true;

    if (n == 0)
        return false;

    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n - 1] > s)
    {
        dp[n][s] = subset_sum(n - 1, a, s);
        return dp[n][s]; 
    }

    dp[n][s] = subset_sum(n - 1, a, s - a[n - 1]) || subset_sum(n - 1, a, s);
    return dp[n][s]; 
}

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= 1000; j++)
            {
                dp[i][j] = -1;
            }
        }

        if (subset_sum(n, a, 1000 - m))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}





//#botom up
// #include <bits/stdc++.h>
// using namespace std;

// bool subset_sum(int n, int a[], int s)
// {
//     bool dp[n + 1][s + 1];

//     // Initialize dp array
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= s; j++)
//         {
//             if (j == 0)
//                 dp[i][j] = true;
//             else if (i == 0)
//                 dp[i][j] = false;
//             else if (a[i - 1] <= j)
//                 dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }

//     return dp[n][s];
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int a[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }

//         if (subset_sum(n, a, 1000 - m))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }


//#top down 2
// #include <bits/stdc++.h>
// using namespace std;

// int dp[1005][1005];

// bool subset_sum(int n, int a[], int s)
// {
//     if (n == 0)
//     {
//         if (s == 0)
//             return true;
//         else
//             return false;
//     }
//     if (dp[n][s] != -1)
//         return dp[n][s];
//     if (a[n - 1] <= s)
//     {
//         bool op1 = subset_sum(n - 1, a, s - a[n - 1]);
//         bool op2 = subset_sum(n - 1, a, s);
//         return dp[n][s] = op1 || op2;
//     }
//     else
//     {
//         return dp[n][s] = subset_sum(n - 1, a, s);
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m;
//         cin >> n >> m;
//         int a[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }

//         // Initialize dp array manually
//         for (int i = 0; i <= n; i++)
//         {
//             for (int j = 0; j <= 1000; j++)
//             {
//                 dp[i][j] = -1;
//             }
//         }

//         if (subset_sum(n, a, 1000 - m))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }
