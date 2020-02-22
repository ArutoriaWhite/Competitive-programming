#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int N = 12;

int pascal[N+5][N+5], ans[N+5], flag, tar, n, vis[N+5];

inline void build ()
{
	for (int i=1; i<=N; i++)
	{
		pascal[i][0] = 1;
		for (int j=1; j<i-1; j++)
			pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];	
		pascal[i][i-1] = 1;
	}
}
inline int sum (int d)
{
	int res = 0;
	for (int i=0; i<=d; i++)
		res += ans[i]*pascal[n][i];
	return res;
}
void dfs (int d)
{
	if (d==n)
	{
		if (sum(n-1) == tar)
		{
			for (int i=0; i<n; i++)
				cout << ans[i] << "\n "[i+1<n];
			flag=1;
		}
		return;
	}
	
	for (int i=1; i<=n; i++)
	{
		ans[d] = i;
		if (!(vis[i] || sum(d)>tar))
			vis[i] = 1, dfs(d+1), vis[i] = 0;
		if (flag) break;
	}
}

inline void print_pascal()
{
	for (int i=1; i<=N; i++)
	{
		for (int j=0; j<N; j++)
			cout << pascal[i][j] << ' ';
		cout << '\n';
	}
}
inline void test_sum ()
{
	while (cin >> n)
	{
		for (int i=0; i<n; i++)
			cin >> ans[i];
		de(sum(n-1));
	}
}

signed main()
{
	akiyama;
	build();
	cin >> n >> tar;
	dfs(0);
}
