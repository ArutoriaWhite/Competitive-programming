#include <bits/stdc++.h>
#define int long long 
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define endl '\n'
#define ff first
#define ss second
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5+10;

int n, k, m, l, a[N];

signed main()
{
	cin >> n >> k >> l;
	m = n*k;
	rep(i,1,m) cin >> a[i];

	sort(a+1,a+1+m);

	int w = upper_bound(a+1,a+1+m,a[1]+l)-a-1;
	int y = m-w;	
	
	if (w < n)
	{
		cout << 0 << endl;
		return 0;
	}

	int ans = 0, i = 1;
	while (i<=w)
	{
		ans += a[i];
		int cnt = k-1;
		while (cnt>0 && (w-i+y)/k < (w-i)) i++, cnt--;
		y -= cnt;
		i++;
	}
	cout << ans << endl;
}
