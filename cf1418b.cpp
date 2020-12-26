#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int a[N], l[N], t, n;
vector<int> v;

signed main()
{
	XinAi
	cin >> t;
	while (t--)
	{
		v.clear();
		cin >> n;
		rep(i,1,n) cin >> a[i];
		rep(i,1,n) cin >> l[i];
		rep(i,1,n)
			if (!l[i]) v.push_back(a[i]);
		sort(v.begin(), v.end());
		rep(i,1,n)
		{
			cout << (l[i]? a[i]:v.back()) << ' ';
			if (!l[i]) v.pop_back();
		}
		cout << '\n';
	}
}
