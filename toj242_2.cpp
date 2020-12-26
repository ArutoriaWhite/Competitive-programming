#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define MID ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
const int N = 6e6;

struct Node {int cnt=0, lc=0, rc=0;};
struct ST
{
    Node st[N<<2];
    int ls[N<<2], rs[N<<2], lz[N<<2], tt=1;
    inline void init()
    {
        memset(lz,-1,sizeof(lz));
    }
     inline Node merge(Node a, Node b)
    {
        return {a.cnt+b.cnt-(a.rc&&b.lc), a.lc, b.rc};
    }
    inline void upd (int u, int x)
    {
        if (x==-1) return;
        st[u] = {x,x,x};
        lz[u] = x;
    }
    inline void push (int u)
    {   
        if (!ls[u]) ls[u]=++tt;
        if (!rs[u]) rs[u]=++tt;
        if (lz[u]==-1) return;
        upd(ls[u],lz[u]), upd(rs[u],lz[u]);
        lz[u] = -1;
    }
    inline void radd (int u, int l, int r, int ql, int qr, int x)
    {
        if (l>qr || ql>r) return;
        if (ql<=l && r<=qr) upd(u,x);
        else
        {
            push(u);
            radd(ls[u],l,MID,ql,qr,x);
            radd(rs[u],MID+1,r,ql,qr,x);
            st[u] = merge(st[ls[u]],st[rs[u]]);
        }
    }
    inline Node query (int u, int l, int r, int ql, int qr)
    {
        if (l>qr || ql>r) return {0,0,0};
        if (ql<=l && r<=qr) return st[u];
        else
        {
            push(u);
            return merge(query(ls[u],l,MID,ql,qr), query(rs[u],MID+1,r,ql,qr));
        }
    }
} tr;

signed main()
{
    haaachamachama
    int n, q;
    cin >> n;
    tr.init();
    tr.radd(1,0,n,0,0,1);
    cin >> q;
    for (int i=0,x,l,r; i<q; i++)
    {
        cin >> x >> l >> r;
        if (x==1) tr.radd(1,0,n,l,r,1);
        if (x==2) tr.radd(1,0,n,l,r,0);
        if (x==3) cout << tr.query(1,0,n,l,r).cnt << '\n';
    }
}
/*
10
10
2 0 10
3 0 10
1 2 4
3 0 10
1 5 6
3 0 10
2 4 5
3 0 10
3 3 6
3 0 5
*/