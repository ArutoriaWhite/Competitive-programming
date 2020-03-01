#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define exi(x,s) (s.find(x) != s.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb emplace_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
#define int long long
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, M = 1e7+10;

set<int> dp[30][30];
int n, k, owo[30], res, isntp[M];

void build ()
{
	isntp[0] = isntp[1] = 1;
	for (int i=2; i<M; i++)
		if (!isntp[i])
			for (int j=i+i; j<M; j+=i) isntp[j] = 1;
}

signed main()
{
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> owo[i];
	dp[n][0].insert(0);
	for (int i=n-1; i>=0; i--)
	{
		for (int j=0; j<=k; j++)
		{
			for (auto x: dp[i+1][j])
				dp[i][j].insert(x);
			if (j<=0) continue;
			for (auto x: dp[i+1][j-1])
				dp[i][j].insert(x+owo[i]);
		}
	}
	build();
	for (auto x: dp[0][k])
		if (!isntp[x]) res++;
	cout << res << '\n';
}
