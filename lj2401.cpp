#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

int dp[N][N];
/*
dp[i][j] = dp[i-1][j-1] * (i-j) + dp[i-1][j]*(j+1)
dp[i][0] = 1;
*/

signed main()
{
    for (int i=0; i<N; i++) dp[i][0] = 1;
    for (int i=1; i<N; i++)
        for (int j=0; j<i; j++)
            dp[i][j] = (dp[i-1][j-1]*(i-j)%2015 + dp[i-1][j]*(j+1)%2015)%2015;
    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << '\n';
}
