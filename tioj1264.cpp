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
const int N = 5010;

int x[N], y[N], z[N], vis[N], n, d[N], ans;

void prim()
{
    mem(d,0x7f);
    d[1] = 0;
    rep(t,1,n)
    {
        int a=-1, mind = 9e18;
        rep(i,1,n)
        {
            if (vis[i]) continue;
            if (d[i]>=mind) continue;
            mind = d[i];
            a = i;
        }
        if (a<0) break;
        ans += mind;
        vis[a] = 1;
        rep(i,1,n)
        {
            if (vis[i]) continue;
            int w = (x[i]-x[a])*(x[i]-x[a])+(y[i]-y[a])*(y[i]-y[a])+(z[i]-z[a])*(z[i]-z[a]);
            d[i] = min(d[i], w);
        }
    }
}

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> x[i] >> y[i] >> z[i];
    prim();
    cout << ans << '\n';
}