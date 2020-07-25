#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1000, M = 504;

int dp[N<<1][N<<1], n, k, ans;

int main()
{
    cin >> n >> k;
    k = min(k, 2*n-1);
    dp[1][1] = dp[1][0] = 1;
    for (int i=2; i<=2*n-1; i++)
    {
        for (int j=1; j<=k; j++)
        {
            int len = i + i%2 - 1;
            for (int p=1; p<i; p++)
                dp[i][j] = (dp[i][j] + dp[p][j-1])%M;
            dp[i][j] = (dp[i][j]*max(0,(len - j + 1)))%M;
        }
    }
    for (int i=1; i<=2*n-1; i++)
        ans = (ans + dp[i][k])%M;
    cout << ans << '\n';
}