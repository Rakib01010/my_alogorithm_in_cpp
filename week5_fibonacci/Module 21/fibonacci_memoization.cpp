#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll save[N];
ll fibo(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    // it catch the saved and return that fot memoization
    if (save[n] != -1)
    {
       cout <<"memoization number are: "<< n << " "<<endl;  //2 3
        return save[n];
    }
    ll ans1 = fibo(n - 1);
    ll ans2 = fibo(n - 2);
    return save[n] = ans1 + ans2;
    ;
}
int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }
    cout << fibo(n) << endl;
    cout <<  save[0] << endl;
    return 0;
}

// 5 output 8

// With Memoization (using the if (save[n] != -1) check):
//  fibo(5)
//  save[5] = -1 (not memoized, so we calculate)
//  fibo(4)
//  save[4] = -1 (not memoized, so we calculate)
//  fibo(3)
//  save[3] = -1 (not memoized, so we calculate)
//  fibo(2)
//  save[2] = -1 (not memoized, so we calculate)
//  fibo(1)
//  save[1] = 1 (base case, memoize)
//  fibo(0)
//  save[0] = 1 (base case, memoize)
//  save[2] = 2 (memoize)
//  save[3] = 3 (memoize)
//  save[4] = 5 (memoize)
//  save[5] = 8 (memoize)
//  In this case, we calculate each Fibonacci value once and memoize it. The total number of function calls is 6, and the result for fibo(5) is 8.

// Without Memoization (removing the if (save[n] != -1) check):

// fibo(5)
// fibo(4)
// fibo(3)
// fibo(2)
// fibo(1)
// fibo(0)
// fibo(1)
// fibo(2)
// fibo(3)
// fibo(2)
// fibo(1)
// fibo(0)
// Without memoization, the code repeatedly recalculates Fibonacci values, even for the same values of n. This results in a total of 12 function calls, and the result for fibo(5) is still 8, but the calculations are inefficient and redundant.