#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 5e5+10;

deque<int> dq; // id, less
int n, k, h[N], b[N];

signed main()
{
	XinAi
	cin >> n >> k;
	rep(i,1,n) cin >> h[i];
	rep(i,1,n) cin >> b[i];
	int ans=0, val=0, id;
	rep(i,1,n)
	{
		while (!dq.empty() && h[dq.back()] <= h[i]) ans-=b[dq.back()], dq.pop_back();
		while (!dq.empty() && dq.front()<i-k+1) ans-=b[dq.front()], dq.pop_front();
		dq.push_back(i);
		ans += b[i];
		if (ans > val)
		{
			val = ans;
			id = i;
		}
	}
	cout << id << ' ' << val << '\n';
}

