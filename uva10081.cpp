#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

/*
dp[i][j]
dp[ [0,i) ][end of j] = num of solution
dp[i][j] = dp[i-1][j+1] + dp[i-1][j] + dp[i-1][j-1];
dp[0][0~k] = 1

res = dp[n][i]
*/
int n, k;
double dp[110][10], res;

int main()
{
    while (cin >> k >> n)
    {
        Eriri
        memset(dp,0,sizeof(dp));
        for (int i=0; i<=k; i++) dp[1][i] = (double)1/(k+1);
        res = 0;
        for (int i=2; i<=n; i++)
        {
            for (int j=0; j<=k; j++)
            {
                dp[i][j] += dp[i-1][j];
                if (j+1<=k) dp[i][j] += dp[i-1][j+1];
                if (j-1>=0) dp[i][j] += dp[i-1][j-1];
                dp[i][j] /= (k+1);
            }
        }
        for (int i=0; i<=k; i++)
            res += dp[n][i];
        cout << fixed << setprecision(5) << res*100 << '\n';
    }
}
