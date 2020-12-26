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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 3010, M = 998244353;

int dp[N][N];

int f (int x, int y)
{
    if (x==1 && y==1) return 1;
    if (x<=0 || y<=0) return 0;
    if (dp[x][y]<0)
    {
        dp[x][y] = 0;
        for (int i=0; (1<<i)*x<=y; i++)
        {
            dp[x][y] += f((1<<i)*x-1, y-1);
            dp[x][y] %= M;
        }
    }
    return dp[x][y];
}
signed main()
{
    int k, x;
    mem(dp,-1);
    cin >> x >> k;
    cout << f(k,x) << '\n';
}