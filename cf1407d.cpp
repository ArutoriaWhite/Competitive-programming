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
const int N = 3e5+10;

int a[N], n;
stack<int> st; // id in 

vector<int> dp1[N], dp2[N];
int dp[N];

inline void sol (vector<int> *ans)
{
	while (!st.empty()) st.pop();
	rep(i,1,n)
	{
		while (!st.empty() && a[st.top()]<a[i])
			ans[i].push_back(st.top()), st.pop();
		if (!st.empty()) ans[i].push_back(st.top());
		if (!st.empty() && a[st.top()]==a[i]) st.pop();
		st.push(i);
	}
}

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> a[i];
	sol(dp1);
	rep(i,1,n) a[i] *= -1;
	sol(dp2);
	rep(i,2,n)
	{
		dp[i] = 0x3f3f3f3f;
		for (auto x: dp1[i]) dp[i]=min(dp[i],dp[x]+1);
		for (auto x: dp2[i]) dp[i]=min(dp[i],dp[x]+1);
	}
	cout << dp[n] << '\n';
}
//dp[1]=0
