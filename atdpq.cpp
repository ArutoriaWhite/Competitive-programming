#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;
/*
dp[i] = max(dp[j] + w[i], a[j] < a[i], 1<=j<i)
*/
int st[N<<1], n, h[N], w[N], res, dp;
int query(int l, int r)
{
    int res = 0;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if (l&1) res = max(res, st[l++]);
        if (r&1) res = max(res, st[--r]);
    }
    return res;
}
void modify(int p, int x)
{
    p--;
    for (st[p+=n]=x; p>1; p>>=1)
        st[p>>1] = max(st[p],st[p^1]);
}

signed main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> h[i];
    for (int i=1; i<=n; i++)
        cin >> w[i];
    for (int i=1; i<=n; i++)
    {
        dp = query(0,h[i]) + w[i];
        res = max(res, dp);
        modify(h[i],dp);
    }
    cout << res << '\n';
}
