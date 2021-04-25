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

const int N = 260, A = N*300;

int vis[N][N];
bitset<A> dp[N];
int n, k, a, b, w[N];
set<int> s;

signed main()
{
	pui
	cin >> n >> k >> a >> b;
	rep(i,1,n) cin >> w[i];
	
	dp[0][0] = 1;
	for (int i=1; i<=n; i++)
		for (int j=k; j>0; j--)
				dp[j] |= dp[j-1]<<w[i];
	for (int i=0; i<A; i++)
		if (dp[k][i])
				s.insert(i);
	int ans = 0;
	for (int i=a; i<=b; i++)
	{
		int owo = 0;
		if (i <= *s.begin())
		   	owo = *s.begin()-i;	
		else if (*s.rbegin() <= i)
			owo = i-*s.rbegin();
		else
			owo = min(*s.upper_bound(i)-i, i-*prev(s.upper_bound(i)));
		ans = max(ans, owo);
	}
	cout << ans << endl;
}
