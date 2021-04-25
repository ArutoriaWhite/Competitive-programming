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

const int N = 1e6+10, P = 1e9+7;

int qpow (int i, int j)
{
	int res = 1;
	for (; j; j>>=1,i=i*i%P)
		if (j&1)
			res = (res*i)%P;
	return res;
}

signed main()
{
	pui
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int ans = 1;
		rep(i,1,m)
			ans = (ans + qpow(n,i)*(1+(min(i,n)+1)%P*(min(i,n))%P*qpow(2,P-2)%P))%P;
		cout << ans << endl;
	}
}
