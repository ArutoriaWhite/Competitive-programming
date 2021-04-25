#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

const int N = 1e6+10;
const double EPS = 1e-7;

int n, h, x[N], y[N];

vector<pdd> lines;
vector<pdd> s;

inline int cross (int a, int b, int c, int d)
{
    return a*d - b*c;
}
inline void equation (int a1, int a2, int b1, int b2, int c1, int c2, double &x, double &y)
{
    int delta = cross(a1,b1,a2,b2);
    int deltax = cross(c1,b1,c2,b2);
    int deltay = cross(a1,c1,a2,c2);
    //de(delta), de(deltax), de(deltay), dd;
    x = (double)deltax/delta;
    y = (double)deltay/delta;
}
inline double sol (int i, int j)
{
    double m, k;
    equation(x[i],x[j],1,1,y[i],y[j],m,k);
    return (h-k)/m;
}

inline void gen_lines()
{
    for (int i=3; i<n; i+=2)
    {
        double l = sol(i-1,i);
        double r = sol(i,i+1);
        lines.pb({l,r});
    }
}
inline void gen_lines2()
{
    for (int i=3; i<n; i+=2)
    {
        double l = -9e18;
        double r = 9e18;
        for (int j=2; j<i; j+=2)
        {
            l = max(l, sol(j,i));
        }
        for (int j=i+1; j<=n; j+=2)
        {
            r = min(r, sol(i,j));
        }
        lines.pb({l,r});
    }
}
void test()
{
    int a1, a2, b1, b2, c1, c2;
    double x, y;
    while (cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2)
    {
        equation(a1,a2,b1,b2,c1,c2,x,y);
        de(x), de(y), dd;
    }
}

signed main()
{
    ShinraTensei
    //test();
    cin >> n >> h;
    rep(i,1,n)
        cin >> x[i] >> y[i];

    gen_lines();

    for (auto x: lines)
    {
        if (s.empty() || EPS < x.ff - s.back().ss)
        {
            s.pb(x);
        }
        else
        {
            s.back().ff = max(s.back().ff, x.ff);
            s.back().ss = min(s.back().ss, x.ss);
        }
        //de(x.ff), de(x.ss), dd;
    }
    cout << s.size() << '\n';
}