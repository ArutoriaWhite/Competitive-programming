#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, M = 50;

int dp[M][M][M][M], w[400], c[5], owo, m;

int sol (int c1, int c2, int c3, int c4, int n)
{
	int &res = dp[c1][c2][c3][c4];
	if (dp[c1][c2][c3][c4] < 0)
	{
		res = 0;
		if (c1>0) res = max(res, sol(c1-1,c2,c3,c4,n+1));
		if (c2>0) res = max(res, sol(c1,c2-1,c3,c4,n+2));
		if (c3>0) res = max(res, sol(c1,c2,c3-1,c4,n+3));
		if (c4>0) res = max(res, sol(c1,c2,c3,c4-1,n+4));
		res += w[n];
	}
	return dp[c1][c2][c3][c4];
}
int main()
{
	mem(dp,-1);
	cin >> owo >> m;
	for (int i=1; i<=owo; i++) cin >> w[i];
	for (int i=0,x; i<m; i++) cin >> x, c[x]++;
	cout << sol(c[1],c[2],c[3],c[4],1) << '\n';
}

