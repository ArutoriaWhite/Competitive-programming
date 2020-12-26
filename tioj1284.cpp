#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define mem(x,v) memset(x,v,sizeof(x))
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

double m[N], k[N];
int n;

double f (double x)
{
	double mxval, mnval;
	rep(i,1,n)
	{
		if (i==1 || m[i]*x+k[i]>mxval)
			mxval = m[i]*x+k[i];
		if (i==1 || m[i]*x+k[i]<mnval)
			mnval = m[i]*x+k[i];
	}
	return mxval-mnval;
}

double ts ()
{
	double l=0, r=9e18;
	while (r-l > 1e-9)
	{
		double m1 = (l*2+r)/3;
		double m2 = (r*2+l)/3;
		if (f(m1) < f(m2)) r = m2;
		else l = m1;
	}
	return f(l);
}

signed main()
{
	cin >> n;
	rep(i,1,n) cin >> m[i] >> k[i];
	cout << fixed << setprecision(2) << ts() << '\n';
}
