#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

struct nod { int l, m, r;} st[N<<2];
int arr[N], n, q;

inline nod merge (const nod &a, const nod &b, int l, int r)
{
    int m = (l+r)>>1;
    nod res = { a.l, max(a.m,b.m), b.r };
    if (arr[m-1]+1 == arr[m])
    {
        if (a.l == m-l)
            res.l += b.l;
        if (b.r == r-m)
            res.r += a.r;
        res.m = max( res.m, a.r + b.l);
    }
    return res;
}
void build (int l, int r, int id)
{
    if (r-l <= 1)
        st[id] = {1,1,1};
    else
    {
        int m = (l+r)>>1;
        build(l,m,id<<1);
        build(m,r,id<<1|1);
        st[id] = merge(st[id<<1], st[id<<1|1], l, r);
    }
}
void modify (int l, int r, int p, int x, int id)
{
    if (r-l <= 1)
        arr[p] = x;
    else
    {
        int m = (l+r)>>1;
        if (l<=p && p<m) modify(l,m,p,x,id<<1);
        if (m<=p && p<r) modify(m,r,p,x,id<<1|1);
        st[id] = merge(st[id<<1], st[id<<1|1], l, r);
    }
}
nod query (int l, int r, int ql, int qr, int id)
{
    if (qr<=l || r<=ql) return {0,0,0};
    if (ql<=l && r<=qr) return st[id];
    int m = (l+r)>>1;
    return merge( query(l,m,ql,qr,id<<1), query(m,r,ql,qr,id<<1|1) ,l,r);
}

int main()
{
    Eriri
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    build(0,n,1);
    cin >> q;
    for (int i=0,a,b,c; i<q; i++)
    {
        cin >> a >> b >> c;
        if (a==1) modify(0,n,b-1,c,1);
        else
        {
            nod res = query(0,n,b-1,c,1);
            cout << max(res.l, max(res.r, res.m)) << '\n';
        }
    }
}
