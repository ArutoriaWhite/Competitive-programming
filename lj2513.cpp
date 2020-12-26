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
const int N = 1010, M = 10000;

int dp[N], sum[N], n, k;

signed main()
{
    cin >> n >> k;
    dp[0] = 1;
    rep(i,1,n)
    {
        rep(j,1,k+1) sum[j] = (dp[j-1]+sum[j-1])%M;
        rep(j,1,k) dp[j] = (sum[j+1]-sum[max(0LL,j-i+1)]+M)%M;
    }
    cout << dp[k] << '\n';
}
/*

*/