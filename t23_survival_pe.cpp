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

int n, m, q;
int lx, ly, sx, sy;

int calc()
{
	int dx = min(abs(lx-sx), abs(n-abs(lx-sx)));
	int dy = min(abs(ly-sy), abs(m-abs(ly-sy)));
	return dx*dx + dy*dy;
}

signed main()
{
	ShinraTensei
	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			char c;
			cin >> c;
			if (c=='L') lx = i, ly = j;
			if (c=='S') sx = i, sy = j;
		}
	}
	cin >> q;
	int ans=0;
	int mndis = calc();
	for (int i=1; i<=q; i++)
	{
		char c;
		int k;
		cin >> c >> k;
		if (c=='x')
		{
			k %= m;
			sy = (sy+k+m)%m;
		}
		else
		{
			k %= n;
			sx = (sx-k+n)%n;
		}
		if (calc() < mndis)
		{
			ans = i; 
			mndis = calc();
		}
	}
	cout << ans << '\n';
}
