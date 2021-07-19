#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;
int n, m;
struct Seg
{
    int tr[N<<2], lz[N<<2];
    void upd (int u, int x) //change tr and lazy tag
    {
        lz[u] += x;
        tr[u] += x;
    }
    void push (int u) // clear u's lazy tag, upd subnodes
    {
        upd(u<<1,lz[u]);
        upd(u<<1|1,lz[u]);
        lz[u] = 0;
    }
    void pull (int u) // calc new u value by subnodes
    {
        tr[u] = min(tr[u<<1], tr[u<<1|1]);
    }
/*     void build (int u, int l, int r) //assign to leafs, update u
    {
        if (l == r)
            tr[u] = a[l];
        else
        {
            int m = (l+r)/2;
            build(u<<1,l,m);
            build(u<<1|1,m+1,r);
            pull(u);
        }
    } */
    void modify (int ql, int qr, int x, int u=1, int l=1, int r=n)
    {
        if (ql>r || l>qr) return;
        if (ql<=l && r<=qr) upd(u,x);
        else
        {
            int m = (l+r)/2;
            push(u);
            modify(ql,qr,x,u<<1,l,m);
            modify(ql,qr,x,u<<1|1,m+1,r);
            pull(u);
        }
    } 
    int query (int ql, int qr, int u=1, int l=1, int r=n)
    {
        if (ql>r || l>qr) return 9e18;
        if (ql<=l && r<=qr) return tr[u];
        push(u);
        int m = (l+r)/2;
        return min(query(ql,qr,u<<1,l,m), query(ql,qr,u<<1|1,m+1,r));
    }
} seg;

signed main()
{
    pui
    cin >> n >> m;
    while (m--)
    {
        int o, l, r, x;
        cin >> o >> l >> r;
        l++;

        if (o == 1)
            cin >> x, seg.modify(l,r,x);
        else
            cout << seg.query(l,r) << endl;
    }
}