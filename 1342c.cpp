#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define endl '\n'
#define ff first
#define ss second
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define int long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

int q, a, b, t;

signed main()
{
	pui
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> q;
		int k = a*b/__gcd(a,b);
		if (a > b) swap(a,b);
		while (q--)
		{
			int l, r;
			cin >> l >> r;
			int lid = l/k;
			int rid = r/k;
			int ans = 0;
			if (a == b)
			{
				cout << 0 << endl;
				continue;
			}
			else if (lid == rid)
			{
				l = max(l%k, b), r = min(r%k,k-1);
				ans = max(0LL, r-l+1);
			}
			else
			{
				ans += (k-b)*(rid-lid-1);	
				ans += k - max(l%k,b);
				ans += max(r%k-b+1,0LL);
			}
			cout << ans << ' ';
		}
		cout << endl;
	}

}
