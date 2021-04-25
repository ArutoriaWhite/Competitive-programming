#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

int G[N][N], n, m;
int vis[N][N], sh[][2] = {{1,0},{-1,0},{0,1},{0,-1}}, lim;

inline void dfs (int r, int c)
{
	if (r>n || r<1 || c>m || c<1) return;
	if (vis[r][c] || G[r][c]>lim) return;

	vis[r][c] = 1;

	for (int i=0; i<4; i++)
	{
		int nr = r+sh[i][0];
		int nc = c+sh[i][1];
		dfs(nr,nc);
	}
}
inline int check (int l)
{
	memset(vis,0,sizeof(vis));
	lim = l;
	rep(i,1,m) dfs(1,i);
	rep(i,1,m)
		if (!vis[n][i])
			return 0;
	return 1;
}

inline int bs()
{
	int i=-1, s=1010;
	while (s > 0)
	{
		if (check(i+s)) s>>=1;
		else i+=s;
	}
	return i+1;
}

signed main()
{
	cin >> n >> m;
	rep(i,1,n)
		rep(j,1,m)
			cin >> G[i][j];
	cout << bs() << '\n';
}
