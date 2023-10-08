#include <bits/stdc++.h>
using namespace std;

int countWaysToTargetSum(int a[], int n, int target)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if ((sum + target) % 2 != 0)
        return 0;

    int s1 = (sum + target) / 2;

    int dp[n + 1][s1 + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s1; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s1; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][s1];
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
    int target;
    cin >> target;

    int ways = countWaysToTargetSum(a, n, target);

    cout << "Number of ways to achieve the target sum " << target << " is: " << ways << endl;

    return 0;
}



//================================top down

// #include <bits/stdc++.h>
// using namespace std;

// int countWaysToTargetSum(int a[], int n, int target)
// {
//     // Calculate the sum of all elements in the array
//     //way 1    === accumulate(the start , the last , initial value);
//     //int sum = accumulate(a, a + n, 0);
    
//     //way 2
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += a[i];
//     }
//     if ((sum + target) % 2 != 0)
//         return 0;

//     int s1 = (sum + target) / 2;

//    // vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
//     int dp[n+1][s1+1];
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= s1; j++)
//         {
//             dp[i][j]=0;
//         }
//     }
   
//     // There is one way to reach a sum of 0, which is by not selecting any element
//     for (int i = 0; i <= n; i++)
//         dp[i][0] = 1;
//     //dp
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= s1; j++)
//         {
//             if (a[i - 1] <= j)
//                 dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }

//     return dp[n][s1];
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
//     int target;
//     cin >> target;

//     int ways = countWaysToTargetSum(a, n, target);

//     cout << "Number of ways to achieve the target sum " << target << " is: " << ways << endl;

//     return 0;
// }


// 4
// 1 1 2 3
// 1

// 3