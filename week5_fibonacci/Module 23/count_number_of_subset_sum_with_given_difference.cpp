#include <bits/stdc++.h>
using namespace std;
int count_number_of_subset_sum_with_given_difference(int n, int a[], int s)
{
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][s];
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dif;
    cin >> dif;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    int s1 = (dif + sum) / 2;

    int count = count_number_of_subset_sum_with_given_difference(n, a, s1);

    cout << count << endl;

    return 0;
}

//================================top down
// #include <bits/stdc++.h>
// using namespace std;

// int dp[1005][1005];

// int count_subsets(int n, int a[], int s)
// {
//     if (n == 0)
//     {
//         if (s == 0)
//             return 1; // Found a valid subset
//         else
//             return 0;
//     }
//     if (dp[n][s] != -1)
//         return dp[n][s];
//     int include_current = 0;
//     int exclude_current = 0;
//     if (a[n - 1] <= s)
//     {
//         include_current = count_subsets(n - 1, a, s - a[n - 1]);
//     }
//     exclude_current = count_subsets(n - 1, a, s);
//     return dp[n][s] = include_current + exclude_current;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     int difference;
//     cin >> difference;
//     int sum = accumulate(a, a + n, 0);
//     int s1 = (difference + sum) / 2;
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= s1; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }
//     int count = count_subsets(n, a, s1);
//     cout << "Number of subsets with difference " << difference << " is: " << count << endl;
//     return 0;
// }

// 4
// 1 1 2 3
// 1

// 3