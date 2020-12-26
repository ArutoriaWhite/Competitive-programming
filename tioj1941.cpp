#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <iostream>
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
const int N = 8e5+10;

template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}

int n, st[N<<2], lz[N<<2];
void add (int u, int l, int r, int ql, int qr, int x)
{
    if (ql<=l && r<=qr) lz[u] += x, st[u] += x;
    else
    {
        int m = (l+r)>>1;
        if (!(m<ql || qr<l))   add(u<<1,l,m,ql,qr,x);
        if (!(r<ql || qr<m+1)) add(u<<1|1,m+1,r,ql,qr,x);
        st[u] = max(st[u<<1], st[u<<1|1]) + lz[u];
    }
}
void modify (int u, int l, int r, int p, int x)
{
    if (l==p && p==r) st[u] = x;
    else
    {
        int m = (l+r)>>1;
        if (!(m<p || p<l)) modify(u<<1, l, m, p, x-lz[u]);
        if (!(r<p || p<m+1)) modify(u<<1|1, m+1, r, p, x-lz[u]);
        st[u] = max(st[u<<1], st[u<<1|1]) + lz[u];
    }
}
int query (int u, int l, int r, int ql, int qr)
{
    if (r<ql || qr<l) return 0;
    if (ql<=l && r<=qr) return st[u];
    int m = (l+r)>>1;
    int ans=0;
    if (!(m<ql || qr<l))   ans = max(ans, query(u<<1,l,m,ql,qr));
    if (!(r<ql || qr<m+1)) ans = max(ans, query(u<<1|1,m+1,r,ql,qr));
    return ans + lz[u];
}

signed main()
{
    XinAi
    in(n);
    for (int i=0,s,t; i<n; i++)
    {
        in(s), in(t);
        modify(1,0,n-1,s,query(1,0,n-1,0,s));
        add(1,0,n-1,s,t,1);
    }
    cout << query(1,0,n-1,0,n-1) << '\n';
}