#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 110, M = 1000007;

// dp[i][j][k] 正在選擇第 i 種花, 已經選了幾個, 總共多少花
// dp[i][j][k] = dp[i][j+1][k+1] + dp[i+1][0][k]
// dp[i][j][m] =

int n, m, a[N];
ll dp[N][N][N];

ll f (int i, int j, int k)
{
    if (dp[i][j][k] == -1)
    {
        if (k==m) dp[i][j][k] = 1;
        else
        {
            dp[i][j][k] = 0;
            if (i < n)
                dp[i][j][k] += f(i+1,0,k), dp[i][j][k]%=M;
            if (j < a[i])
                dp[i][j][k] += f(i,j+1,k+1), dp[i][j][k]%=M;
        }
    }
    return dp[i][j][k]%M;
}

signed main ()
{
    yukari;
    mem(dp,-1);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cout << f(1,0,0) << '\n';
}