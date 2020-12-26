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
const int N = 1e6+10;

struct Node {int cnt=0, lc=0, rc=0;};
struct ST
{
    Node st[N<<2];
    int lz[N<<2];
    inline Node merge (Node a, Node b)
    {
        Node res = {a.cnt+b.cnt, a.lc, b.rc};
        if (a.rc == 1 && b.lc==1) res.cnt--;
        return res;
    }
    inline void upd (int u, int x)
    {
        if (x==-1) return;
        st[u] = {x,x,x};
        lz[u] = x;
    }
    inline void pull (int u)
    {
        st[u] = merge(st[u<<1], st[u<<1|1]);
    }
    inline void push (int u)
    {
        upd(u<<1,lz[u]), upd(u<<1|1,lz[u]), lz[u]=-1;
    }
    inline void rset (int u, int l, int r, int ql, int qr, int x)
    {
        push(u);
        if (l>qr || ql>r) return;
        else if (ql<=l && r<=qr) upd(u,x);
        else
        {
            rset(u<<1,l,MID,ql,qr,x);
            rset(u<<1|1,MID+1,r,ql,qr,x);
            pull(u);
        }
    }
    inline Node query (int u, int l, int r, int ql, int qr)
    {
        push(u);
        if (l>qr || ql>r) return {0,0,0};
        else if (ql<=l && r<=qr) return st[u];
        else
        {
            return merge(query(u<<1,l,MID,ql,qr), query(u<<1|1,MID+1,r,ql,qr));
        }
    }
    inline void init()
    {
        memset(lz, -1, sizeof(lz));
    }
} st;
vector<int> tL, tR, v, qL, qR, qX;

signed main()
{
    haaachamachama
    int n, q;
    cin >> n >> q;
    v.push_back(0);
    v.push_back(1);
    for (int i=0,x,l,r; i<q; i++)
    {
        cin >> x >> l >> r;
        qX.push_back(x);
        tL.push_back(l);
        tR.push_back(r);
        v.push_back(l);
        v.push_back(r);
        v.push_back(r+1);
    }
    sort(v.begin(), v.end());
    v.resize(n=unique(v.begin(), v.end())-v.begin());
    for (auto i: tL) qL.push_back(lower_bound(v.begin(),v.end(),i)-v.begin()+1);
    for (auto i: tR) qR.push_back(lower_bound(v.begin(),v.end(),i)-v.begin()+1);
    st.init();
    st.rset(1,1,n,1,1,1);
    for (int i=0; i<q; i++)
    {
        if (qX[i] == 1) st.rset(1,1,n,qL[i],qR[i],1);
        if (qX[i] == 2) st.rset(1,1,n,qL[i],qR[i],0);
        if (qX[i] == 3) cout << st.query(1,1,n,qL[i],qR[i]).cnt << '\n';
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

3
4
1 0 3
3 0 3
2 1 2
3 0 3
*/