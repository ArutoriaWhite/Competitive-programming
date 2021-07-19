#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
using namespace std;

int n, q;
struct Seg
{
    int tr[N<<2];
    void add (int u=1, int l=1, int r=n, int i, int x)
    {
        if (i<l || r<i)
            return;
        if (l==i && i==r)
            tr[u] += x;
        else
        {
            int m = (l+r)>>1;
            add(u<<1,l,m,i,x), add(u<<1|1,m+1,r,i,x);
        }
    }
    int query (int u=1, int l=1, int r=n, int ql, int qr)
    {
        if (qr<l || r<ql)
            return 0;
        if (ql<=l && r<=qr)
            return tr[u];
            
        int m = (l+r)>>1;
        return max(query(u<<1,l,m,ql,qr), query(u<<1|1,m+1,r,ql,qr));
    }
} st;

signed main()
{
    cin >> n >> q;
    while (q--)
    {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 1)
            add(a,b);
        if (o == 2)
            cout << query(a,b) << endl;
    }
}