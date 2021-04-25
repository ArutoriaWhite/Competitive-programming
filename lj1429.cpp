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

const int N = 2e5+10;

pii a[N], tmp[N];
int n;

inline int cmp (pii i, pii j)
{
	return i.ss < j.ss;
}

int dis (pii i, pii j)
{
	return (i.ff-j.ff)*(i.ff-j.ff) + (i.ss-j.ss)*(i.ss-j.ss);
}

int solve (int l, int r)
{
	if (r-l+1 <= 3)
	{
		int ans = 9e18;
		rep(i,l,r)
			rep(j,i+1,r)
				ans = min(ans, dis(a[i],a[j]));
		sort(a+l,a+r+1,cmp);
		return ans;
	}

	int mid = (l+r)/2;
	int midx = a[mid].ff;	
	int ans = min(solve(l,mid), solve(mid+1,r));
	double realAns = sqrt(ans);
	// collect left side and right side close to mid
	vector<pii> L, R;
	rep(i,l,mid)
		if (midx - a[i].ff < realAns)
			L.pb(a[i]);
	rep(i,mid+1,r)
		if (a[i].ff - midx < realAns)
			R.pb(a[i]);
	
	// enum left side, right side climb, right side enum from pointer
	int lb = 0;
	for (auto p: L)
	{
		while (lb<R.size() && R[lb].ss <= p.ss - ans) lb++;
		for (int i=lb; i<R.size()&&R[i].ss<p.ss+ans; i++)
		{
			if (ans > dis(p,R[i]))
			{
				ans = dis(p,R[i]);
				realAns = sqrt(ans);
			}	
		}
	}
	
	merge(a+l,a+mid+1,a+mid+1,a+r+1,tmp+l,cmp);
	rep(i,l,r) a[i] = tmp[i];

	return ans;	
}

signed main()
{
	pui
	cin >> n;
	rep(i,1,n) cin >> a[i].ff >> a[i].ss;
	sort(a+1,a+1+n);
	cout << fixed << setprecision(4) << sqrt(solve(1,n)) << '\n';
}
