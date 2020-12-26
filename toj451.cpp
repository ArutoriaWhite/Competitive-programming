#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 510, M = 1e9+7;

int cylen[N];

int qpow (int x, int y)
{
	int res = 1;
	for (; y; y>>=1,x=(x*x)%M)
		if (y&1) res = res*x%M;
	return res;
}

signed main()
{
	int n, m, c;
	cin >> n >> m >> c;
	c = qpow(c,n*n);
	int res = 0;
	rep(i,1,m)
	{
		if (m%i) continue;
		cylen[i] = qpow(c,i);
		rep(j,1,i-1)
		{
			if (i%j == 0)
				cylen[i] = (cylen[i] - cylen[j]*j%M +M)%M;
		}
		cylen[i] = (cylen[i]*qpow(i,M-2))%M;
		res = (res+cylen[i])%M;
	}
	cout << res << '\n';
}
