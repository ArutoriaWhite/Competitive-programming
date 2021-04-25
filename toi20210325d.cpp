#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << endl;
#define endl '\n'
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 60;

char c[N][N];

int n, m, vis[N][N];

void dfs2 (int i, int j)
{
	if (i<1 || i>n || j<1 || j>m || vis[i][j] || c[i][j]!='X')
		return;
	vis[i][j] = 1;
	dfs2(i+1,j), dfs2(i-1,j), dfs2(i,j+1), dfs2(i,j-1);
}
int dfs (int i, int j)
{
	if (i<1 || i>n || j<1 || j>m || vis[i][j] || c[i][j]=='.')
		return 0;
	vis[i][j] = 1;
	if (c[i][j] == 'X')
	{
		dfs2(i,j);
		return 1+dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1);
	}
	else
		return dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1);
}

signed main()
{
	pui
	int cnt = 0;
	while (cin >> n >> m, n&&m)
	{
		swap(n,m);
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				cin >> c[i][j];
				vis[i][j] = 0;
			}
		}
		vector<int> ans;
		rep(i,1,n)
			rep(j,1,m)
				if (!vis[i][j])
				{
					int owo = dfs(i,j);
					if (owo > 0) ans.pb(owo);
				}
		sort(ans.begin(), ans.end());
		cout << "Throw " << ++cnt << endl;
		for (int i=0; i<ans.size(); i++)
			cout << ans[i] << "\n "[i+1<ans.size()];
	}
}
