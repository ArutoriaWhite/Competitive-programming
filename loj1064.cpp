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
const int INF=0x7f7f7f7f, N = 4e4, M = 1e2;

int p[M], w[M], v, n, item[M][5], dp[N][M], r[M];

int sol (int rest, int i, int k)
{
	if (rest<0) return 0;
	if (dp[rest][i] == -1)
	{
		if (i>n) dp[rest][i] = 0;
		else if (r[i]<=0) dp[rest][i] = sol(rest,i+1,0);
		else
		{
			int p1=p[item[i][1]], p2=p[item[i][2]];
			int w1=w[item[i][1]], w2=w[item[i][2]];
			dp[rest][i] = max(dp[rest][i], sol(rest-p[i],i+1,w[i]));
			dp[rest][i] = max(dp[rest][i], sol(rest-p[i]-p1,i+1,w[i]+w1));
			dp[rest][i] = max(dp[rest][i], sol(rest-p[i]-p2,i+1,w[i]+w2));
			dp[rest][i] = max(dp[rest][i], sol(rest-p[i]-p1-p2,i+1,w[i]+w1+w2));
			dp[rest][i] = max(dp[rest][i], sol(rest,i+1,0));
		}
	}
	return dp[rest][i]+k;
}

inline void print_items()
{
	for (int i=0; i<=n; i++)
	{
		if (r[i]<=0) continue;
		int p1=p[item[i][1]], p2=p[item[i][2]], w1=w[item[i][1]], w2=w[item[i][2]];
		de(i), de(p[i]), de(p1), de(p2), de(w[i]), de(w1), de(w2), dend;
	}
}

int main()
{
	akiyama;
	mem(dp,-1);
	cin >> v >> n;
	for (int i=1,b; i<=n; i++)
	{
		cin >> p[i] >> w[i] >> b, w[i]*=p[i];
		if (b>0) item[b][r[b]++] = i;
		else item[i][r[i]++] = i;
	}
	cout << sol(v,0,0) << '\n';
}
