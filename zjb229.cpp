#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int unsigned long long
using namespace std;
typedef pair<int,int> pii;
const int N = 100;

int dp[N];

signed main()
{
    dp[0] = 1, dp[1] = 3;
    for (int i=2; i<N; i++) dp[i] = (dp[i-1]-dp[i-2])*2 + dp[i-2]*3;
    int n; cin >> n; cout << dp[n] << '\n';
}