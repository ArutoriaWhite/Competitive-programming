#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;
const double EPS = 1e-4;

int a[N], n, mn=9e18, mx=-9e18;
double p[N]; 

double f (double x)
{
    double minp=0, maxp=0, ans=-DBL_MAX;
    rep(i,1,n)
    {
        p[i] = p[i-1] + a[i]-x;
        ans = max(ans, abs(p[i]-minp));
        ans = max(ans, abs(p[i]-maxp));
        minp = min(minp, p[i]);
        maxp = max(maxp, p[i]);
    }
    return ans;
}
double ts ()
{
    double m1, m2, l=mn, r=mx;
    while (abs(r-l)>1e-9)
    {
        m1 = l+(r-l)/3;
        m2 = r-(r-l)/3;
        if (f(m1)>f(m2)) l=m1;
        else r=m2;
    }
    return (l+r)/2;
}

signed main()
{
    shaaark
    cin >> n;
    rep(i,1,n) cin >> a[i], mn=min(mn,a[i]), mx=max(mx,a[i]);
    cout << fixed << setprecision(3) << f(ts()) << '\n';
}
