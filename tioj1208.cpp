#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e4+10;

int a[N], t[N], p[N], n, k;

int bigthan (int l, int r, int x)
{
    if (l >= r) return 0;
    int m = (l+r)>>1, res = bigthan(l,m,x) + bigthan(m+1,r,x);
    for (int i=l,j=m+1; j<=r; j++)
    {
        while (i<=m && p[j]-p[i]>x) i++;
        res += i-l;
    }
    merge(p+l, p+m+1, p+m+1, p+r+1, t+l);
    for (int i=l; i<=r; i++) p[i] = t[i];
    return res;
}
int bs()
{
    int i=-3e8, s = 5e8;
    while (s)
    {
        for (int i=1; i<=n; i++) p[i] = p[i-1] + a[i-1];
        int owo = bigthan(0, n, i+s);
        if (owo >= k) i += s;
        else s >>= 1;
    }
    return i+1;
}
signed main()
{
    XinAi
    while (cin >> n >> k, n||k)
    {
        for (int i=0; i<n; i++) cin >> a[i];
        cout << bs() << '\n';
    }
}