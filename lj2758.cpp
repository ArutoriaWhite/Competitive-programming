#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2010;

string a, b;
int dp[N][N], n, m;

int main()
{
    Eriri
    cin >> a >> b;
    n = a.size();
    m = b.size();
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i) dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
            if (j) dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
            if (i && j) dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
            if (i && j && a[i-1] == b[j-1]) dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
        }
    }
    cout << dp[n][m] << '\n';
}