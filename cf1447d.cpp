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

string a, b;
int dp[N][N], n, m;

signed main()
{
    ShinraTensei
    cin >> n >> m >> a >> b;
    int res=0;
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i==0) dp[i][j] = -j;
            else if (j==0) dp[i][j] = -i;
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])-1;
                dp[i][j] = max(dp[i][j], (-2LL +(a[i-1]==b[j-1])*4) );
                if (a[i-1]==b[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res << '\n';
}