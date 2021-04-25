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
const int N = 160, M = 1000000009;

int n, m, q, l;

struct mat
{
	int a[N][N] = {0};
	mat operator* (mat &b)
	{
		mat res;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++)
					res.a[i][j] = (a[i][k]*b.a[k][j]%M + res.a[i][j])%M;
		return res;
	}
	void unit ()
	{
		for (int i=0; i<n; i++)
			a[i][i] = 1;
	}
} adj;

mat qpow (mat x, int i)
{
	mat res; res.unit();
	for (; i; i>>=1,x=x*x)
		if (i&1)
			res = res*x;
	return res;
}

signed main()
{
	ShinraTensei
	cin >> n >> m >> q >> l;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj.a[u][v]++;
	}

	adj = qpow(adj,l);

	while (q--)
	{
		int u, v;
		cin >> u >> v;
		cout << adj.a[u][v] << '\n';
	}
}
