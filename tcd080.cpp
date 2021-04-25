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
const int N = 20;

int a[N], dp[N][N], n, res;

signed main()
{
    string s;
    cin >> s;
    n = s.size();
    for (int i=0; i<n; i++)
        a[i+1] = s[i]-'0';

    // build dp;
    rep(i,0,9) dp[1][i] = 1;
    rep(i,2,n)
        rep(j,0,9)
            rep(k,j,9)
                dp[i][j] += dp[i-1][k];

    rep(i,1,n+1)
    {
        if (i == n+1)
        {
            res++;
            break;
        }
        if (a[i] < a[i-1]) break;
        rep(j,a[i-1],a[i]-1)
            res += dp[n-i+1][j];
    }

    cout << res-1 << '\n';
}