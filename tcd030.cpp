#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int x[N], h[N], nfall[N], n, l;
stack<int> stk;

signed main()
{
	ShinraTensei
	cin >> n >> l;
	rep(i,1,n) cin >> x[i];
	rep(i,1,n) cin >> h[i];
	
	x[n+1] = l;
	rep(i,1,n+1)
	{
		while (!stk.empty() && x[stk.top()]+h[stk.top()] <= x[i])
			stk.pop();
		if (x[i]-h[i]>=0)
			if (stk.empty() || x[i]-h[i]>=x[stk.top()])
				continue;
		stk.push(i);
	}
	while (!stk.empty())
	{
		nfall[stk.top()] = 1;
		stk.pop();
	}

	int cnt=0, ans=0;
	rep(i,1,n)
	{
		if (!nfall[i])
		{
			cnt++;
			ans = max(ans, h[i]);
		}
	}
	cout << cnt << '\n' << ans << '\n';
}
/*
4 70
10 20 30 50
20 10 60 30
*/

