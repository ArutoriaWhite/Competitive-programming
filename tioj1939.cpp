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
const int N = 110, M = 1e9+9;

int dp[N], dp2[N];

signed main()
{
    dp[1] = dp2[1] = 1;
    for (int i=2; i<N; i++)
    {
        dp[i] = ((dp[i-1]*3)%M + dp2[i-1])%M;
        dp2[i] = (dp2[i-1] + (dp[i-1]*2)%M)%M;
    }
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}