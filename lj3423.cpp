#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 2805, M = 2e4+5;

int n, k, c[205], v[205];
vector<int> nc, nv, tp;
int dp[2][M], m;
bitset<M> choose[N];

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> v[i];
    rep(i,1,n) cin >> c[i];
    cin >> k;

    nc.reserve(N);
    nv.reserve(N);
    tp.reserve(N);
    nc.pb(0), nv.pb(0), tp.pb(0);
    rep(i,1,n)
    {
        for (int j=1; c[i]-j>=0; j*=2)
        {
            nc.pb(j);
            nv.pb(v[i]*j);
            tp.pb(i);
            c[i] -= j;
        }
        nc.pb(c[i]);
        nv.pb(c[i]*v[i]);
        tp.pb(i);
    }
    m = n;
    n = nc.size();
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=k; j++)
        {
            dp[i%2][j] = dp[(i+1)%2][j];
            if (j >= nv[i])
            {
                if (dp[i%2][j] > dp[(i+1)%2][j-nv[i]]+nc[i])
                {
                    dp[i%2][j] = dp[(i+1)%2][j-nv[i]]+nc[i];
                    choose[i][j] = 1;
                }
            }
        }
    }
    cout << dp[n%2][k] << '\n';
    memset(v,0,sizeof(v));
    while (n > 0)
    {
        if (choose[n][k])
        {
            v[tp[n]] += nc[n];
            k -= nv[n];
        }
        n--;
    }
    rep(i,1,m) cout << v[i] << ' '; dd
}
