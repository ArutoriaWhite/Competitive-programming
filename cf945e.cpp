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
#define double long double
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;
const double EPS = 1e-8;

int n, T;
pii a[N]; //{temp, x}
int xsum[N], xtsum[N];

void build()
{
	rep(i,1,n)
	{
		xsum[i] = xsum[i-1] + a[i].ss;
		xtsum[i] = xtsum[i-1] + a[i].ff*a[i].ss;
	}
}
int calc (int l, int r, double p=0, double q=0)
{
	if (l>r) return q > 1.0*T*p;
	return (xtsum[r]-xtsum[l-1]+q) > 1.0*T*(xsum[r]-xsum[l-1]+p);
}
int good (int l, int r)
{
	return (xtsum[r]-xtsum[l-1]) == T*(xsum[r]-xsum[l-1]);
}
double bs1 (int i) // find max p such that 1..i-1, p of i, calc 0
{
	double p=0, s=a[i].ss;
	while (s > EPS)
	{
		if (!calc(1,i-1,(p+s),(p+s)*a[i].ff)) p += s;
		else s /= 2;
	}	
	return p;
}
double bs2 (int i)
{
	double p=0, s=a[i].ss;
	while (s > EPS)
	{
		if (calc(i+1,n,p+s,(p+s)*a[i].ff)) p += s;
		else s /= 2;
	}
	return p;
}

signed main()
{
	pui
	cin >> n >> T;
	rep(i,1,n) cin >> a[i].ss;
	rep(i,1,n) cin >> a[i].ff;
	
	sort(a+1,a+1+n); // sort by temperature
	build();

	if (T<a[1].ff || a[n].ff<T)
	{
		cout << 0 << endl;
		return 0;
	}
	if (T==a[1].ff)
	{
		int res = 0, i=0;
		while (i+1<=n && a[i+1].ff==a[1].ff)
			i++, res += a[i].ss;
		cout << res << endl;
		return 0;
	}
	if (T==a[n].ff)
	{
		int res = 0, i=n+1;
		while (i-1>0 && a[i-1].ff==a[n].ff)
			i--, res += a[i].ss;
		cout << res << endl;
		return 0;
	}

	double ans;
	if (calc(1,n,0,0))
	{
		int i=1;
		while (!calc(1,i)) i++;
		double xts = xtsum[i-1];
		double xs = xsum[i-1];
		double t = a[i].ff;
		ans = (xts-T*xs)/(T-t) + xs;
	}
	else
	{
		int i=n;
		while (calc(i,n)) i--;
		double xts = xtsum[n]-xtsum[i];
		double xs = xsum[n]-xsum[i];
		double t = a[i].ff;
		ans = (xts-T*xs)/(T-t) + xs;
	}
	cout << fixed << setprecision(7) << ans << endl;
}

