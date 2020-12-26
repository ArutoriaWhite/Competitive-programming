#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define double long double
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int x[N], y[N], s[N], n;

inline int check (double v)
{
    double curtime=0;
    rep(i,1,n)
    {
        curtime += 1.0*s[i]/v;
        if (curtime > y[i])
        {
            return 0;
        }
        curtime = max(curtime, (double)x[i]);
    }  
    return 1;
}
inline double bs ()
{
    double l=0, r=1e10;
    while (r-l > 1e-5)
    {
        double m = (l+r)/2;
        if (check(m)) r=m;
        else l=m;
    }
    return l;
}

signed main()
{
    SakuraMyWife;
    cin >> n;
    rep(i,1,n) cin >> x[i] >> y[i] >> s[i];
    cout << fixed << setprecision(2) << bs() << '\n';   
}