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
const int N = 1e3+10;

int a[N], n, t, ans[N];

signed main()
{
	XinAi
	cin >> t;
	while (t--)
	{
		memset(ans,0,sizeof(ans));
		cin >> n;
		rep(i,1,n) cin >> a[i];
		sort(a+1,a+1+n,[](int i,int j){return i>j;});
		ans[1] = a[1];
		a[1] = -1;
		int cur=ans[1];
		rep(i, 2, n)
		{
			int owo = 0;
			rep(j, 1, n)
			{
				if (a[j] == -1) continue;
				if (ans[i]==0 || __gcd(a[j],cur)>__gcd(ans[i],cur))
						ans[i] = a[j], owo=j;
			}
			cur = __gcd(ans[i], cur);
			a[owo] = -1;
		}
		rep(i,1,n) cout << ans[i] << ' ';
		cout << '\n';
	}
}
