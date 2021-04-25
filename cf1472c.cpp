#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
/*
dp[i]: score he can win if he start from i
dp[i] = a[i] + dp[i+a[i]]
*/
const int N = 2e5+10;
int a[N], dp[N], t, n;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep (i,1,n) cin >> a[i];
        
        int ans = 0;
        for (int i=n; i>0; i--)
        {
            dp[i] = a[i];
            if (i + a[i] <= n)
                dp[i] += dp[i+a[i]];
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}