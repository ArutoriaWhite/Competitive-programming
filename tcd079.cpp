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
const int N = 210;

int dp[N][N], p[N], n, l;

signed main()
{
    cin >> n >> l;
    rep(i,1,n) cin >> p[i];

    mem(dp,0x3f);
    p[n+1] = l;

    for (int l=0,r=1; r<=n+1; l++,r++)
        dp[l][r] = 0;
    for (int i=2; i<=n+1; i++)
        for (int l=0,r=i; r<=n+1; l++,r++)
            for (int k=l+1; k<r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k]+dp[k][r]+p[r]-p[l]);
    
    cout << dp[0][n+1] << '\n';
}