#include <iostream>
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
const int N = 5010;

int dp[2][N], n, m, ans;
long long bns;
string s;

signed main()
{
	ShinraTensei
	cin >> n >> m;
	rep(i,1,n)
	{
		cin >> s;	
		rep(j,1,m)
		{
			dp[i&1][j] = (min(dp[i&1][j-1], min(dp[(i+1)&1][j], dp[(i+1)&1][j-1]))+1)*(s[j-1]=='0');
			ans = max(ans, dp[i&1][j]);
			bns += dp[i&1][j];
		}
	}
	cout << bns << ' ' << ans << '\n';
}

