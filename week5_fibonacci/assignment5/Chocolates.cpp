// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1001;
// const int max_sum = 2001;
// int dp[N][max_sum];
// vector<int> boxes;

// bool can_give_equal_chocs(int i, int sum1, int sum2)
// {
//     if (sum1 == sum2 && i == 0)
//     {
//         return true;
//     }

//     if (i == 0)
//     {
//         return false;
//     }

//     if (dp[i][sum1] != -1)
//     {
//         return dp[i][sum1];
//     }
//     // bool res1 = can_give_equal_chocs(i - 1, sum1 + boxes[i - 1], sum2);
//     // bool res2 = can_give_equal_chocs(i - 1, sum1, sum2 + boxes[i - 1]);
//     bool can_give = can_give_equal_chocs(i - 1, sum1 + boxes[i - 1], sum2) ||
//                     can_give_equal_chocs(i - 1, sum1, sum2 + boxes[i - 1]);

//     dp[i][sum1] = can_give;

//     return can_give;
// }

// int main()
// {
//     int cas;
//     cin >> cas;

//     while (cas--)
//     {
//         int n;
//         cin >> n;

//         boxes.clear();
//         boxes.resize(n);

//         int total_chocs = 0;

//         for (int i = 0; i < n; i++)
//         {
//             cin >> boxes[i];
//             total_chocs += boxes[i];
//         }

//         if (total_chocs % 2 != 0)
//         {
//             cout << "NO" << endl;
//         }
//         else
//         {
//             for (int i = 0; i <= n; i++)
//             {
//                 for (int j = 0; j <= total_chocs; j++)
//                 {
//                     dp[i][j] = -1;
//                 }
//             }

//             if (can_give_equal_chocs(n, 0, 0))
//             {
//                 cout << "YES" << endl;
//             }
//             else
//             {
//                 cout << "NO" << endl;
//             }
//         }
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
const int max_sum = 2001;
vector<int> chocs(N);
bool dp[max_sum];

bool can_give_equal_chocs(int n, int target) 
{
    dp[0] = true;
    for (int i = 0; i < n; i++) 
    {
        for (int j = target; j >= chocs[i]; j--) 
        {
            if (dp[j - chocs[i]])
                dp[j] = true;
        }
    }

    return dp[target];
}

int main() 
{
    int t;
    cin >> t;
    
    while (t--) 
    {   
        int n;
        cin >> n;
        int total_chocs = 0;

        for (int i = 0; i < n; i++) 
        {
            cin >> chocs[i];
            total_chocs += chocs[i];
        }

        if (total_chocs % 2 != 0) 
        {
            cout << "NO" << endl; 
        }
        else
        {
            int target = total_chocs / 2;

            for (int i = 0; i <= target; i++) 
            {
                dp[i] = false;
            }
            
            //can be given equally or not
            if (can_give_equal_chocs(n, target))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}

