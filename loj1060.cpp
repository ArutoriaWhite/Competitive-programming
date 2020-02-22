#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 30, V = 3e4+10;

int w[N], p[N], v, dp[N][V], n, m;

int f (int i, int s)
{
	if (i==m) return 0;
	if (dp[i][s] == -1)
	{
		if (s > p[i]) dp[i][s] = f(i+1,s-p[i]) + w[i];
		dp[i][s] = max( dp[i][s], f(i+1,s));
	}
	return dp[i][s];
}

int main()
{
	akiyama;
	mem(dp,-1);
	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> p[i] >> w[i], w[i]*=p[i];
	cout << f(0,n) << '\n';
}
