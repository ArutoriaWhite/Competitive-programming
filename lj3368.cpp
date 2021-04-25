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
#define low(x) (x&(-x))
using namespace std;
typedef pair<int,int> pii;

const int N = 5e5+10;

int tr[N], a[N], n, m;

inline void add (int i, int x)
{
	for(; i<=n; i+=low(i))
		tr[i] += x;
}
inline int query (int i)
{
	int ans = 0;
	for (; i>0; i-=low(i))
		ans += tr[i];
	return ans;
}

signed main()
{
	pui
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) add(i,a[i]-a[i-1]);
	while (m--)
	{
		int o, x, y, k;
		cin >> o;
		if (o == 1)
			cin >> x >> y >> k, add(x,k), add(y+1,-k);
		else if (o == 2)
			cin >> x, cout << query(x) << endl;
	}
}

