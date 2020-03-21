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
const int INF=0x7f7f7f7f, N = 1e4+10;

int G[N][N], colo[N][N], ans[N*N], cnt, n, m;

void dfs (int x, int y, int c, int g)
{
	if (x<0 || x>=n || y<0 || y>=n || colo[x][y]!=-1 || g!=G[x][y]) return;
	colo[x][y] = c, ans[c]++;
	dfs(x+1,y,c,!G[x][y]), dfs(x-1,y,c,!G[x][y]);
	dfs(x,y+1,c,!G[x][y]), dfs(x,y-1,c,!G[x][y]);
}
signed main()
{
	mem(colo,-1);
	cin >> n >> m;
	string s;
	for (int y=0; y<n; y++)
	{
		cin >> s;
		for (int x=0; x<n; x++)
			G[x][y] = s[x]-'0';
	}
	for (int i=0,x,y; i<m; i++)
	{
		cin >> x >> y;
		swap(x,y), x--, y--;
		if (colo[x][y] == -1) dfs(x,y,i,G[x][y]);
		else ans[i] = ans[colo[x][y]];
	}
	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
	return 0;
}
