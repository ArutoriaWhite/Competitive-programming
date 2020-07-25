#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 3010;

Pii a[N];
int dp[N];
int n, m, k, ans;

inline bool cmp (Pii x, Pii y)
{
    return x.S/x.F > y.S/y.F;
}

signed main()
{
    Eriri
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i].F >> a[i].S;
    sort(a+1,a+n+1,cmp);
    for (int t=m-k,i=1; t>0; i++)
    {
        if (t > a[i].F)
        {
            t -= a[i].F;
            ans += a[i].S;
        }
        else
        {
            ans += a[i].S/a[i].F*t;
            t = 0;
        }
    }
    for (int i=1; i<=n; i++)
        for (int j=m; j>=a[i].F; j--)
            dp[j] = max(dp[j], dp[j-a[i].F]+a[i].S);
    cout << max(ans, dp[m]) << '\n';
}