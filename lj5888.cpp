#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define all(v) v.begin(), v.end()
using namespace std;
typedef pair<int,int> pii;
const int N = 5e4+10, M = 210, MOD = 998244353;

int n, m, k, nn;
vector<int> hate[N];
vector<pii> inp;
int sum[M], dp[M][N];

int f (int i, int j)
{
    if (i==0) return (j==0);
    if (dp[i][j]<0)
    {
        dp[i][j] = 0;
        if (sum[i-1] < 0)
        {
            sum[i-1] = 0;
            rep(s,0,nn) sum[i-1] = (sum[i-1]+f(s,i-1))%MOD;
        }
    }
    dp[i][j] = sum[i-1];
    return dp[i][j];
}

signed main()
{
    cin >> n >> m >> k;
    for (int i=0,a,b; i<k; i++)
    {
        cin >> a >> b;
        apr.pb(a), apr.pb(b);
        if (a!=b) inp.pb({a,b});
    }
    apr.pb(1);
    sort(all(apr));
    nn = unique(all(apr))-apr.begin();
    for (auto p: inp)
    {
        int a = lower_bound(all(apr),p.ff)-apr.begin();
        int b = lower_bound(all(apr),p.ss)-apr.begin();
        hate[a].pb(b);
    }
    cout << f(0,m) << '\n';
}