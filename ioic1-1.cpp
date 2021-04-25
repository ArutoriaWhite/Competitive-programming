#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+10;

int n, q;
int sum[N<<2], mx[N<<2], len[N<<2], lzadd[N<<2], lzset[N<<2], a[N];

void upd (int u, int addx, int setx) // apply modify to u and change tag
{
    if (setx)
    {
        sum[u] = len[u]*setx;
        mx[u] = setx;
        lzset[u] = setx;
        lzadd[u] = 0;
    }
    else if (addx)
    {
        sum[u] += len[u]*addx;
        mx[u] += addx;
        if (lzset[u])
            lzset[u] += addx;
        else
            lzadd[u] += addx;
    }
}
void push (int u)
{
    if (len[u] <= 1) return;
    upd(u<<1,lzadd[u],lzset[u]);
    upd(u<<1|1,lzadd[u],lzset[u]);
    lzadd[u] = 0;
    lzset[u] = 0;
}
void pull (int u)
{
    if (len[u] <= 1) return;
    sum[u] = sum[u<<1] + sum[u<<1|1];
    mx[u] = max(mx[u<<1],mx[u<<1|1]);
}
void build (int u, int l, int r)
{
    if (l==r)
    {
        len[u] = 1;
        sum[u] = mx[u] = a[l];
        return;
    }
    int M = (l+r)>>1;
    build(u<<1,l,M);
    build(u<<1|1,M+1,r);
    len[u] = len[u<<1]+len[u<<1|1];
    pull(u);
}
pii query (int u, int l, int r, int ql, int qr) // sum, max
{
    if (qr<l || r<ql) return {0,0};
    push(u);
    if (ql<=l && r<=qr) return {sum[u], mx[u]};
    int M = (l+r)>>1;
    pii A = query(u<<1,l,M,ql,qr);
    pii B = query(u<<1|1,M+1,r,ql,qr);
    return {A.ff+B.ff, max(A.ss,B.ss)};
}
void modify (int u, int l, int r, int ql, int qr, int addx, int setx)
{
    if (qr<l || r<ql) return;
    push(u); // clear u tag
    if (ql<=l && r<=qr)
    {
        upd(u,addx,setx);
        return;
    }
    int M = (l+r)>>1;
    modify(u<<1,l,M,ql,qr,addx,setx);
    modify(u<<1|1,M+1,r,ql,qr,addx,setx);
    pull(u);
}

signed main()
{
    ShinraTensei
    cin >> n >> q;
    rep(i,1,n) cin >> a[i];

    build(1,1,n);
    
    while (q--)
    {
        int k, l, r, x;
        cin >> k >> l >> r;
        if (k <= 2) cin >> x;
    
        if (k==1)
            modify(1,1,n,l,r,0,x);
        if (k==2)
            modify(1,1,n,l,r,x,0);
        if (k==3)
            cout << query(1,1,n,l,r).ff << '\n';
        if (k==4)
            cout << query(1,1,n,l,r).ss << '\n';
    }
}