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
const int N = 110, M = 2e5+10;

int w[N], dp[M], n, m, s, tot;

signed main()
{
	ShinraTensei
	cin >> n >> m >> s;
	rep(i,1,n) cin >> w[i], tot+=w[i];
	rep(i,1,n)
		for (int j=m-s; j>=w[i]; j--)	
			dp[j] = max(dp[j], dp[j-w[i]]+w[i]);
	cout << tot - dp[m-s] << '\n';
}
