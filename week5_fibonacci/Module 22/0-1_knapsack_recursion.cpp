#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int s, int v[], int w[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (w[n - 1] <= s)
    {   //array count from 0 w[n - 1]thats why v[n - 1]  
        // n-1 normlly for decrement like 4 to 3
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        ///// here n=4 and s=7
        //item 1 2 3 4
        //val  1 5 3 2
        //w    5 2 4 3
        return max(op1, op2);
    }
    else
    {
        return knapsack(n - 1, s, v, w);
    }
}
int main()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    cout << knapsack(n, s, v, w);
    return 0;
}
///// here n=4 and s=7
// 4
// 1 5 3 2
// 5 2 4 3
// 7

// output 8
// https://recursion.vercel.app/
// def fn(n, s):
//     if n == 0 or s == 0:
//         return 0
//     if w[n - 1] <= s:
//         op1 = fn(n - 1, s - w[n - 1]) + v[n - 1]
//         op2 = fn(n - 1, s)
//         return max(op1, op2)
//     else:
//         return fn(n - 1, s)