#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

int dp[N], n, h[N];

signed main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> h[i];
    dp[n-1] = abs(h[n]-h[n-1]);
    for (int i=n-2; i>0; i--)
    {
        dp[i] = min(dp[i+1] + abs(h[i] - h[i+1]),dp[i+2] + abs(h[i] - h[i+2]));
    }
    cout << dp[1] << '\n';
}