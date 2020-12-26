#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define MID ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5, M = 1e5+10;

struct Q {int l, r, c;} q[M];
struct ST
{
    int st[M<<2], lz[M<<2];
    inline void push (int u, int l, int r)
    {
        if (lz[u])
        {
            st[u<<1] = MID-l, st[u<<1|1] = r-MID;
            lz[u<<1] = 1, lz[u<<1|1] = 1;
        }        
    }
    inline void rset (int u, int l, int r, int ql, int qr)
    {
        if (l>=qr || ql>=r) return;
        if (ql<=l && r<=qr) st[u]=r-l,lz[u]=1;
        else
        {
            push(u,l,r);
            rset(u<<1,l,MID,ql,qr);
            rset(u<<1|1,MID,r,ql,qr);
            st[u] = (st[u<<1] + st[u<<1|1]);
        }
    }
    inline int query (int u, int l, int r, int ql, int qr)
    {
        if (l>=qr || ql>=r) return 0;
        if (ql<=l && r<=qr) return st[u];
        else
        {
            push(u,l,r);
            return query(u<<1,l,MID,ql,qr) + query(u<<1|1,MID,r,ql,qr);
        }
    }
} tr;

vector<pii> stk;
inline void insert (int l, int r, int c)
{
    //de(l), de(r);
    //de(tr.query(1,0,N,l,r));
    c -= tr.query(1,0,N,l,r);
    if (c<=0)
    {
        //dd;
        return;
    }
    int nl = r-c;
    while (!stk.empty() && stk.back().ss>nl)
    {
        pii t = stk.back();
        //de((t.ss-max(nl,t.ff)));
        nl -= t.ss-t.ff;
        //de(t.ff), de(t.ss);
        stk.pop_back();
    }
    //de(nl), de(r);
    stk.push_back({nl,r});
    tr.rset(1,0,N,nl,r);
    //de(tr.query(1,0,N,l,r)), dd
}

signed main()
{
    haaachamachama
    int n;
    while (cin >> n, n)
    {
        memset(tr.st, 0, sizeof(tr.st));
        memset(tr.lz, 0, sizeof(tr.lz));
        stk.clear();
        rep(i,1,n) cin >> q[i].l >> q[i].r >> q[i].c;
        sort(q+1,q+1+n,[](Q i, Q j){return i.r<j.r;});
        rep(i,1,n) insert(q[i].l, q[i].r, q[i].c);
        cout << tr.query(1,0,N,0,N) << '\n';
    }
}
/*
3
1 6 5
2 5 2
3 6 2
*/