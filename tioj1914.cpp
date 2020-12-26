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

int a[N], t[N], dp[N][N], n, m, k, T;

signed main()
{
    XinAi
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i=1; i<=n; i++) cin >> a[i];
        k = 0;
        for (int i=1; i<=n; i++)
            if (a[i] != a[i-1]) t[++k] = a[i];
        memset(dp, 0x3f, sizeof(dp));
        for (int i=1; i<=k; i++) dp[i][i] = 1;
        for (int len=2; len<=k; len++)
        {
            for (int l=1,r=len; r<=k; l++,r++)
            {
                for (int m=l; m<r; m++)
                    dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r]);
                if (t[l] == t[r]) dp[l][r]--;
            }
        }
        cout << dp[1][k] << '\n';
    }
}