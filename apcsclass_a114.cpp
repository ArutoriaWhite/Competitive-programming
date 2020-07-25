#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans[15];

inline int avai (int x)
{
    while (x)
    {
        if ((x%10)&1) return 0;
        x /= 10;
    }
    return 1;
}

inline int cnt (int x)
{
    int res = 0;
    while (x) x/=10, res++;
    return res;
}

signed main()
{
    for (int i=1000000; i>0; i--)
        if (avai(i*i))
            ans[cnt(i*i)] = i*i;
    cin >> n;
    for (int i=0,x; i<n; i++)
        cin >> x, cout << ans[x] << '\n';
}