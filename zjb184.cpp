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
const int N = 1e6, V = 110;

int dp[V], n, v[N], w[N];

signed main()
{
    XinAi
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) cin >> v[i] >> w[i];
        for (int i=1; i<=n; i++)
            for (int j=100; j>0; j--)
                if (j >= v[i]) dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        cout << dp[100] << '\n';
    }
}