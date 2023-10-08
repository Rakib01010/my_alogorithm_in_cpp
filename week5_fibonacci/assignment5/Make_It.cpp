// #include<bits/stdc++.h>
// using namespace std;
// const int N = 100005;
// int ar[N];
// void make_minus()
// {
//     for(int i=0;i<N;i++)
//     {
//         ar[i]=-1;
//     }
// }
// bool can_reach(int n)
// {
//     //base case
//     if (n == 1)
//         return true;
//     if (n < 1)
//         return false;

//     if (ar[n] != -1)
//         return ar[n];

//     bool can = false;
//     if (n % 2 == 0)
//     {
//         can = can || can_reach(n / 2);
//     }
//     can = can || can_reach(n - 3);

//     ar[n] = can;
//     return can;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n;
//         cin >> n;
//         make_minus();
//         if (can_reach(n))
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

#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
bool ar[M];
void make_fasle()
{
    for(int i=0;i<=M;i++)
    {
       ar[i]=false;
    }
}
int main()
{
    int cas;
    cin >> cas;

    while (cas--)
    {  
        int n;
        cin >> n;
        make_fasle();
        ar[1] = true;

        for (int i = 1; i <= n; i++)
        {
            if (ar[i])
            {
                if (i + 3 <= n)
                {
                    ar[i + 3] = true;
                }
                if (i * 2 <= n)
                {
                    ar[i * 2] = true;
                }
            }
        }

        if (ar[n])
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
