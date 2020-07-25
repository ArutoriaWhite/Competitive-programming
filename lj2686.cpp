#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

int n, l, h, a[N], s[N], dp[N][N];

signed main()
{
    Eriri
    cin >> n >> l >> h;
    for (int i=1; i<=n; i++)
        cin >> a[i], a[i] += a[i-1];
    for (int i=1; i<=n; i++)
        cin >> s[i], s[i] += s[i-1];
    for (int i=n; i>=0; i--)
    {
        for (int j=n; j>=i; j--)
        {
            dp[i][j] = max( dp[i+1][j], dp[i][j+1]);
            if (l<=a[j]-a[i] && a[j]-a[i]<=h)
                dp[i][j] = max( dp[i][j], dp[i+1][j+1]+s[j]-s[i]);
        }
    }
    cout << dp[0][0] << '\n';
}