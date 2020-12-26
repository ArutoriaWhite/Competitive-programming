#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define M ((l+r)>>1)
using namespace std;
const int N = 2e5+10;

int st[N<<2], a[N], n, m;
void build (int u, int l, int r)
{
    if (l==r) st[u]=a[l];
    else
    {
        build(u<<1,l,M), build(u<<1|1,M+1,r);
        st[u] = max(st[u<<1], st[u<<1|1]);
    }
}
void add (int u, int l, int r, int p, int x)
{
    if (p<l || r<p) return;
    if (l==r) st[u] += x;
    else
    {
        add(u<<1,l,M,p,x), add(u<<1|1,M+1,r,p,x);
        st[u] = max(st[u<<1], st[u<<1|1]);
    }
}
void mod (int u, int l, int r, int ql, int qr, int x)
{
    if (qr<l || r<ql) return;
    if (x>st[u]) return;
    if (l==r) st[u] %= x;
    else
    {
        mod(u<<1,l,M,ql,qr,x), mod(u<<1|1,M+1,r,ql,qr,x);
        st[u] = max(st[u<<1], st[u<<1|1]);
    }
}

signed main()
{
    shaaark
    cin >> n;
    rep(i,1,n) cin >> a[i];
    build(1,1,n);
    cin >> m;
    for (int i=0,k,a,b,c; i<m; i++)
    {
        cin >> k;
        if (k == 1) cin >> a >> b, add(1,1,n,b+1,a);
        if (k == 2) cin >> a >> b >> c, mod(1,1,n,a+1,b+1,c);
        if (k == 3) cout << st[1] << '\n';
    }
}