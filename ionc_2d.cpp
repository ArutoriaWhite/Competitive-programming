#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7+10;

int n, k, b, c, d;
int st[N<<1];

inline int query (int l, int r)
{
    int res = 2e18;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if (l&1) res = min(res, st[l++]);
        if (r&1) res = min(res, st[--r]);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> st[n] >> b >> c >> d;
    for (int i=1; i<n; i++)
        st[i+n] = (st[i+n-1]*b%d+c)%d + i + 1;
    for (int i=n-1; i>0; i--)
        st[i] = min(st[i<<1], st[i<<1|1]);
    int res = 0;
    int len = 2*k+1;
    for (int i=0; i<n; i++)
    {
        int x = 2e18;
        if (len > n)
            x = query(0,n);
        else if (i + len <=n)
            x = min(x, query(i,i+len));
        else
        {
            x = min(x, query(i,n));
            x = min(x, query(0,(i+len)%n));
        }
        res += x;
    }
    cout << res << '\n';
}