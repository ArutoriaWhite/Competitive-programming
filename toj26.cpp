#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define md(x) (x+3)%3
using namespace std;
typedef pair<int,int> Pii;
const int N = 3010;

int dp[3][N], n, t, u, used[N][N];
string s;

int main()
{
	Eriri
	cin >> t;
	while(u++<t)
	{
		cin >> s, n = s.size();
		for (int i=0; i<n; i++) dp[0][i] = 0, dp[1][i] = 1;
		for (int k=2; k<=n; k++)
			for (int i=0; i+k<=n; i++)
				dp[md(k)][i] = (s[i]==s[i+k-1]? dp[md(k-2)][i+1]+2 : max(dp[md(k-1)][i+1],dp[md(k-1)][i]));
		cout << dp[md(n)][0] << '\n';
	}
}