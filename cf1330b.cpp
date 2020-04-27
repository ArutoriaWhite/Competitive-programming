#include <bits/stdc++.h>
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define L(x) (x<<1)
#define R(x) (x<<1|1)
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

int n, r, llen, rlen, t;
int a[N], res[N], vis[N], st[N<<2];

inline void build()
{
    memset(st,0,sizeof(st));
    for (int i=0; i<n; i++) st[i+n] = a[i];
    for (int i=n-1; i>0; i--) st[i] = max(st[L(i)],st[R(i)]);
}
inline int query (int l, int r)
{
    int res = 0;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if (l&1) res = max( res, st[l++]);
        if (r&1) res = max( res, st[--r]);
    }
    return res;
}

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        for (llen=0,memset(vis,0,sizeof(vis)); llen<n&&!vis[a[llen]]; vis[a[llen]]=1,llen++);
        for (rlen=n,memset(vis,0,sizeof(vis)); rlen>0&&!vis[a[rlen-1]]; vis[a[rlen-1]]=1,rlen--);
        r=0, build();
        for (int i=rlen; i<=llen; i++)
            if (query(0,i)==i && query(i,n)==n-i)
                res[r++] = i;
        cout << r << '\n';
        for (int i=0; i<r; i++)
            cout << res[i] << ' ' << n-res[i] << '\n';
    }
}