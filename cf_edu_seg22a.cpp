#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
#define M ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

struct ST
{
    int st[N<<2], lz[N<<2];
    void push (int u)
    {
        lz[u<<1]+=lz[u], lz[u<<1|1]+=lz[u];
        st[u<<1]+=lz[u], st[u<<1|1]+=lz[u];
        lz[u] = 0;
    }
    void pull (int u)
    {
        st[u] = min(st[u<<1], st[u<<1|1]);
    }
    void radd (int u, int l, int r, int ql, int qr, int x)
    {
        if (ql>r || l>qr) return;
        if (ql<=l && r<=qr) st[u]+=x, lz[u]+=x;
        else
        {
            push(u);
            radd(u<<1,l,M,ql,qr,x), radd(u<<1|1,M+1,r,ql,qr,x);
            pull(u);
        }
    }
    int query (int u, int l, int r, int ql, int qr)
    {
        if (ql>r || l>qr) return 9e18;
        if (ql<=l && r<=qr) return st[u];
        else
        {
            push(u);
            return min(query(u<<1,l,M,ql,qr), query(u<<1|1,M+1,r,ql,qr));
        }
    }
} st;

signed main()
{  
    shaaark
    int n, m;
    cin >> n >> m;
    for (int i=0,a,b,c,d; i<m; i++)
    {
        cin >> a >> b >> c;
        if (a == 1) cin >> d, st.radd(1,1,n,b+1,c,d);
        else cout << st.query(1,1,n,b+1,c) << '\n';
    }
}