#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define SZ(x) ((int)x.size())
#define MID ((l+r)/2)
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6, M = 1e5+10;

struct Line {int u,d,x,type;};
vector<Line> v;

struct ST
{
    int st[(N+10)<<2], lz[(N+10)<<2];
    void pull (int u, int l, int r)
    {
        st[u] = (lz[u]? (r-l):st[u<<1]+st[u<<1|1]);
    }
    inline void radd (int u, int l, int r, int ql, int qr, int x)
    {
        if (l>=qr || ql>=r) return;
        if (ql<=l && r<=qr) lz[u]+=x,pull(u,l,r);
        else radd(u<<1,l,MID,ql,qr,x), radd(u<<1|1,MID,r,ql,qr,x), pull(u,l,r);
    }
} tr;

signed main()
{
    haaachamachama
    int n;
    cin >> n;
    for (int i=0,u,d,l,r; i<n; i++)
    {
        cin >> l >> r >> u >> d;
        v.push_back({u,d,l,1});
        v.push_back({u,d,r,-1});
    }
    sort(v.begin(), v.end(), [](Line i, Line j){return i.x<j.x;});
    long long nowx=v[0].x, res=0;
    for (auto l: v)
    {
        if(l.x!=nowx) res += (l.x-nowx)*tr.st[1];
        tr.radd(1,0,N,l.u,l.d,l.type);
        nowx = l.x;
    }
    cout << res << '\n';
}