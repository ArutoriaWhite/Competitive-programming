#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 25, M = 1010;

int a[N], k, n, t, dp[N][M];

int f (int i, int s)
{
    if (s==k) return 1;
    if (i==n) return 0;
    if (dp[i][s] == -1)
        dp[i][s] = f(i+1,s) | f(i+1,s+a[i]);
    return dp[i][s];
}

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        memset(dp,-1,sizeof(dp));
        cin >> k >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        if (f(0,0)) cout << "YES\n";
        else cout << "NO\n";
    }
}