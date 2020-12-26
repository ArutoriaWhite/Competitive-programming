#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 210;

int dp[N][600], t[N], q, n;

signed main()
{
    SakuraMyWife
    cin >> q;
    while (q--)
    {
        cin >> n;
        rep(i,1,n) cin >> t[i];
        sort(t+1, t+1+n);
        memset(dp,0x3f,sizeof(dp));
        dp[0][0] = 0;
        rep(i,1,n)
            rep(T,1,500)
                for (int x=0; x<T; x++)
                {
                    dp[i][T] = min(dp[i][T], dp[i-1][x]+abs(t[i]-T));
                    //if (dp[i][T] > 1e9) continue;
                    //de(i), de(T), de(x), de(dp[i-1][x]), de(abs(t[i]-T)), de(dp[i][T]), dd;
                }
        int ans=2e18;
        rep(i,1,500)
            ans = min(dp[n][i], ans);
        cout << ans << '\n';
    }
}
/*
1
6
4 2 4 4 5 2

1
7
7 7 7 7 7 7 7
*/