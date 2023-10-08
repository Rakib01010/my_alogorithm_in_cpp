#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll a[n + 1];
    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int ans1 = a[i - 1];
        int ans2 = a[i - 2];
        a[i] = ans1 + ans2;
    }
    cout << a[n] << endl;
    // for (int i = 2; i <= n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    return 0;
}

// 5 output 8