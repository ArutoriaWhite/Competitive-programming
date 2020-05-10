#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 110;

int dp[N][N], a[N], b[N], n, m, t;

int main()
{
    Eriri
    while (cin >> n >> m && (n||m) && ++t)
    {
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];

        memset(dp,0,sizeof(dp));
        for (int i=n-1; i>=0; i--)
        {
            for (int j=m-1; j>=0; j--)
            {
                if (a[i] == b[j]) dp[i][j] = dp[i+1][j+1]+1;
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        cout << "Twin Towers #" << t << "\n";
        cout << "Number of Tiles : " << dp[0][0] << "\n\n";
    }
}