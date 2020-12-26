#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n, m;
struct ST
{
    int st[N<<1], lz[N<<1];
    void print()
    {
        rep(i,1,2*n-1) de(i), de(st[i]), de(lz[i]), dd;
    }
    void push (int p)
    {
        for (int h=__lg(n); h; h--)
        {
            int u = (p>>h);
            lz[u<<1]+=lz[u], lz[u<<1|1]+=lz[u];
            st[u<<1]+=lz[u], st[u<<1|1]+=lz[u];
            lz[u]=0;
        }
    }
    void pull (int p)
    {
        for (; p>1; p>>=1)
            st[p>>1] = min(st[p], st[p^1])+lz[p>>1];
    }
    void radd (int l, int r, int x)
    {
        int tl=l, tr=r;
        push(l+n), push(r+n);
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) st[l]+=x,lz[l]+=x,l++;
            if (r&1) r--,st[r]+=x,lz[r]+=x;
        }
        push(tl+n), push(tr+n);
        pull(tl+n), pull(tr+n);
    }
    int query (int l, int r)
    {
        int ans=9e18;
        push(l+n), push(r+n);
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) ans=min(ans, st[l++]);
            if (r&1) ans=min(ans, st[--r]);
        }
        return ans;
    }
} st;

signed main()
{
    shaaark
    cin >> n >> m;
    for (int i=0,a,b,c,d; i<m; i++)
    {
        cin >> a >> b >> c;
        if (a==1) cin >> d, st.radd(b,c,d);
        else cout << st.query(b,c) << '\n';
    }
}