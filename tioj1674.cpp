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
const int N = 1e13+10, M = 1000000009;

int n, inv2, res;

signed main()
{
	cin >> n;
	inv2 = 1;
	for (int i=M-2,t=2; i; i>>=1,t=t*t%M)
		if (i&1) inv2 = inv2*t%M;
	for (int i=1,j,k; i<=n; i=j+1)
	{
		k = n/i;
		j = n/k;
		res = (res + n%M*((j-i+1)%M)%M)%M;
		res = (res - k%M*((i+j)%M)%M*((j-i+1)%M)%M*inv2%M + M)%M;
	}
	cout << res << '\n';
}
