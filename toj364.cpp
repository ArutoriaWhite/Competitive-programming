#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10, K = 1e4+10;

map<int,int> cost;

signed main()
{
	int n, a, b;
	cin >> n >> a >> b;
	if (a==b)
	{
		cout << 0 << '\n';
		return 0;
	}
	rep(i,1,n)
	{
		int x, c;
		cin >> x >> c;
		if (cost.find(x) != cost.end()) cost[x]=min(cost[x], c);
		else cost[x] = c;
	}
	int res=0x3f3f3f3f;
	for (auto kvp: cost)
	{
		int ai=kvp.F, c=kvp.S;
		if (b*ai%a) continue;
		int aj=b*ai/a;
		if (cost.find(aj)==cost.end()) continue;
		else
		{
			res = min(res, cost[aj]+c);
		}
	}
	cout << (res==0x3f3f3f3f? -1 : res) << '\n';
}

