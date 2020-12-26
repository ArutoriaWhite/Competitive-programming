#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 210;

int m, n, a, b, c, d, dp[N][N][N];
// dp[x][y][i] = max(dp[x-1][y-1][i-1]+w(x,y,i), dp[x][y-1][i], dp[x-1][y][i]);
inline int w (int x, int y, int i){ x--,y--,i--; return (a*i+b*x+c*y)%d; }

signed main()
{
    XinAi
    cin >> m >> n >> a >> b >> c >> d;
    for  (int x=1; x<=m; x++)
    {
        for (int y=1; y<=m; y++)
        {
            for (int i=1; i<=n; i++)
            {
                dp[x][y][i] = dp[x-1][y-1][i-1] + w(x,y,i);
                dp[x][y][i] = max(dp[x][y][i], dp[x][y-1][i]);
                dp[x][y][i] = max(dp[x][y][i], dp[x-1][y][i]);
            }
        }
    }
    cout << dp[m][m][n] << '\n';
}