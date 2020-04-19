#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 50, M = 400;

int dp[N][M][M], n, maxV, maxW, vi[N], wi[N], ci[N];

int f (int i, int v, int w)
{
    if (i>=n) return 0;
    if (dp[i][v][w] == -1)
    {
        dp[i][v][w] = f(i+1,v,w);
        if (v >= vi[i] && w>=wi[i])
            dp[i][v][w] = max( dp[i][v][w], f(i+1,v-vi[i],w-wi[i])+ci[i] );
    }
    return dp[i][v][w];
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> maxV >> maxW >> n;
    for (int i=0; i<n; i++)
        cin >> vi[i] >> wi[i] >> ci[i];
    cout << f(0,maxV,maxW) << '\n';
}