#include <bits/stdc++.h>
#define int long long
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef long double ld;

const int N = 2e5+10;

pii a[N], tmp[N];
int n;

inline int cmp (pii i, pii j)
{
	return i.ss < j.ss;
}

ld dis (pii i, pii j)
{
	return sqrt((i.ff-j.ff)*(ld)(i.ff-j.ff) + (i.ss-j.ss)*(ld)(i.ss-j.ss));
}

ld solve (int l, int r)
{
	if (r-l+1 <= 3)
	{
		ld ans = 9e30;
		rep(i,l,r)
			rep(j,i+1,r)
				ans = min(ans, dis(a[i],a[j]));
		sort(a+l,a+r+1,cmp);
		return ans;
	}

	int mid = (l+r)/2;
	int midx = a[mid].ff;	
	ld ans = min(solve(l,mid), solve(mid+1,r));
	vector<pii> L, R;
	rep(i,l,mid)
		if (midx - a[i].ff < ans)
			L.pb(a[i]);
	rep(i,mid+1,r)
		if (a[i].ff - midx < ans)
			R.pb(a[i]);
	int lb = 0;
	for (auto p: L)
	{
		while (lb<R.size() && R[lb].ss < p.ss - ans) lb++;
		for (int i=lb; i<R.size()&&R[i].ss<=p.ss+ans; i++)
			if (ans > dis(p,R[i]))
				ans = dis(p,R[i]);
	}
	
	merge(a+l,a+mid+1,a+mid+1,a+r+1,tmp+l,cmp);
	rep(i,l,r) a[i] = tmp[i];

	return ans;	
}

signed main()
{
	pui
	while (cin >> n)
	{
		rep(i,1,n)
		{
			signed p, q; cin >> p >> q;
			a[i].ff = p, a[i].ss = q;
		}
		sort(a+1,a+1+n);
		cout << fixed << setprecision(6) << solve(1,n) << '\n';
	}
}
