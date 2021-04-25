#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

vector<int> G[N], leaf;
int n, cnt, rt;

signed main()
{
	cin >> n;
	rep(i,1,n-1)
	{
		int u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	rep(i,1,n)
	{
		if (G[i].size()>2) cnt++, rt=i;
		if (G[i].size()==1)
			leaf.pb(i);
		if (cnt>1)
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	if (rt == 0)
	{
		cout << 1 << '\n';
		cout << leaf[0] << ' ' << leaf[1] << '\n';
	}
	else
	{
		cout << leaf.size() << '\n';
		for (auto l: leaf)
		{
			cout << l << ' ' << rt << '\n';
		}
	}
}
