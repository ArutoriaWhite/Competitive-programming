#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<short,short> pii;
const int N = 1e4+10;

short dp[N][N], cnt[10];
pii from[N][N];
string s;

signed main()
{
	XinAi
	cin >> s;
	for (int i=0; i<SZ(s); i++) cnt[s[i]-'0']++;
	for (int i=0; i<10; i++)
	{
		if (cnt[i]>=1000)
		{
			for (int i=0; i<1000; i++) cout << i;
			cout << '\n';
			return 0;
		}
	}
	int n = SZ(s);
	for (int i=0; i<n; i++) dp[i][i+1] = 1;
	for (int len=2; len<=n; len++)
	{
		for (int l=0,r=len; r<=n; l++,r++)
		{
			if (s[l]==s[r-1]) dp[l][r] = dp[l+1][r-1]+2, from[l][r]={l+1,r-1};
			else
			{
				if (dp[l+1][r]>dp[l][r-1])
				{
					dp[l][r] = dp[l+1][r];
					from[l][r] = {l+1,r};
				}
				else
				{
					dp[l][r] = dp[l][r-1];
					from[l][r] = {l,r-1};					
				}
			}
		}
	}
	string ans;
	int l=0, r=n;
	while (r-l>1)
	{
		if (s[l]==s[r-1]) ans += s[l];
		int p=from[l][r].F, q=from[l][r].S;
		l=p, r=q;
	}
	cout << ans;
	if (l<r) cout << s[l];
	for (int i=SZ(ans)-1; i>=0; i--) cout << ans[i];
	cout << '\n';
}

