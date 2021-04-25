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

int n, v, w[110], c[110], dp[N];

signed main()
{
	cin >> n >> v;
	rep(i,1,n) cin >> w[i];
	rep(i,1,n) cin >> c[i];
	rep(i,1,n)
		for (int j=v; j>=w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
	cout << dp[v] << '\n';
}


