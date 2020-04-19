#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e5+10;

int pre_a[N], pre_b[N], xa, ya, xb, yb, res = INF, n;
Pii pos[N];

inline int calc (int i, int j, int k, int l)
{
    return (i-k)*(i-k) + (j-l)*(j-l);
}
inline bool cmp (Pii a, Pii b)
{
    return calc(xa,ya,a.fi,a.se) < calc(xa,ya,b.fi,b.se);
}

int main()
{
    yukari;
    cin >> xa >> ya >> xb >> yb >> n;
    for (int i=0,x,y; i<n; i++)
    {
        cin >> x >> y;
        pos[i] = {x,y};
    }
    sort(pos,pos+n,cmp);
    /*
    for (int i=0; i<n; i++)
    {
        de(pos[i].fi), de(pos[i].se), dend;
    }
    */
    for (int i=1; i<=n; i++)
    {
        pre_a[i] = calc(xa,ya,pos[i-1].fi,pos[i-1].se);
        pre_b[i] = max(pre_b[i-1], calc(xb,yb,pos[n-i].fi,pos[n-i].se));
    }
    /*
    for (int i=0; i<=n; i++)
        de(pre_a[i]), dend;
    for (int i=0; i<=n; i++)
        de(pre_b[i]), dend;
    */
    for (int i=0; i<=n; i++)
    {
        res = min(res, pre_a[i]+pre_b[n-i]);
    }
    cout << res << '\n';
}