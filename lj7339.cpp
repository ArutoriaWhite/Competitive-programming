#include <bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 3e5+10, LG = 20;

int n, m, k, t;
int a[N], idx[N][LG], l[N<<1], r[N<<1];
int ep[N*2], dp[N][LG];

int min_winner (int i);
int can_win (int i, int lev)
{
	if (dp[i][lev] < 0)
	{
		int owo;
		if (i <= (l[idx[i][lev]]+r[idx[i][lev]])/2)
			owo = idx[i][lev]*2+1;
		else
			owo = idx[i][lev]*2;
		if (lev == k)
			dp[i][lev] = 1;
		else if (can_win(i,lev+1)==0)
			dp[i][lev] = 0;
		else if (a[i]+m < min_winner(owo))
			dp[i][lev] = 0;
		else 
			dp[i][lev] = 1;
	}
	return dp[i][lev];
}
int min_winner (int i)
{
	if (ep[i] < 0)
	{
		ep[i] = 9e18;
		for (int j=l[i]; j<=r[i]; j++)
			if (can_win(j,__lg(i)))
				ep[i] = min(ep[i], a[j]);
	}
	return ep[i];
}
void build (int u=1, int ql=1, int qr=n, int lev=0)
{
	rep(i,ql,qr)
		idx[i][lev] = u, dp[i][lev] = -1;
	l[u] = ql;
	r[u] = qr;
	ep[u] = -1;
	if (ql < qr)
	{
		int mid = (ql+qr)/2;
		build(u*2,ql,mid,lev+1);
		build(u*2+1,mid+1,qr,lev+1);
	}
}

signed main()
{
	pui
	cin >> t;
	while (t--)
	{
		cin >> k >> m;
		n = 1<<k;
		rep(i,1,n) cin >> a[i];
		build();
		cout << (can_win(1,0)? "Kotori":"Yoshino") << '\n';
	}
}
