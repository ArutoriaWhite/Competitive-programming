#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

// dp[i][v] = max{ dp[i+1][v-w[i]]+a[i] |}
vector<Pii> items[N];
int dp[N][N], m, n;

int f (int i, int j)
{
    if (i>=N) return 0;
    if (dp[i][j] == -1)
        for (auto kvp: items[i])
            if (j >= kvp.F)
                dp[i][j] = max( dp[i][j], f(i+1,j-kvp.F)+kvp.S);
    return dp[i][j];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> m >> n;
    for (int i=0,a,b,c; i<n; i++)
    {
        cin >> a >> b >> c;
        items[c].push_back({a,b});
    }
    for (int i=0; i<N; i++)
        items[i].push_back({0,0});
    cout << f(0,m) << '\n';
}