#include <bits/stdc++.h>
#define int __int128
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

const int N = 200;

typedef pii V;

int n, m, r, dp[N][N], illegal[N][N];
V p[N], c[N];

int operator ^ (V i, V j){ return i.ff*j.ss - i.ss*j.ff; }
int operator * (V i, V j){ return i.ff*j.ff + i.ss*j.ss; }
V operator - (V i, V j){ return {j.ff-i.ff, j.ss-i.ss}; }

int inter (V a, V b, V c)
{
	if ((a-c)*(a-b)>=0 && (b-a)*(b-c)>=0)
		return ((a-c)^(a-b))*((a-c)^(a-b)) <= r*r*((a-b)*(a-b));
	return min((c-a)*(c-a),(c-b)*(c-b)) <= r*r;
}

int in ()
{
	signed x; cin >> x; return x;
}

signed main()
{
	n = in(), m = in(), r = in();
	

	rep(i,1,n) p[i].ff = in(), p[i].ss = in();
	rep(i,1,m) c[i].ff = in(), c[i].ss = in();

	for (int i=1; i<=n; i++)
	{
		for (int j=i+2; j<=n; j++)
		{
			if (i==1 && j==n) illegal[i][j] = 1;
			else
			{
				for (int k=1; k<=m; k++)
					if (inter(p[i],p[j],c[k]))
						illegal[i][j] = 1;		
			}
		}
	}

	for (int len=3; len<=n; len++)
	{
		for (int l=1,r=len; r<=n; l++,r++)
		{
			for (int i=l+1; i<r; i++)
				dp[l][r] = max(dp[l][r], dp[l][i]+dp[i][r]);
			dp[l][r] += !illegal[l][r];
		}
	}
	cout << (signed)(dp[1][n]) << endl;	
}
