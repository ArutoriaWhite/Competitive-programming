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
const int N = 10010;

int n;
int a[N], b[N], c[N];

double g (double i)
{
    double res = 0;
    rep(j,1,n)
    {
        double y = a[j]*i*i + b[j]*i + c[j];
        if (j==1 || res>y)
            res = y;
    }
    return res;
}

double search()
{
    double l=0, r=90*24*60;
    while (r-l > 1e-7)
    {
        double m1 = (2*l+r)/3, m2 = (2*r+l)/3;
        if (g(m1) < g(m2)) l = m1;
        else r = m2;
    }
    return l;
}

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> a[i] >> b[i] >> c[i];
    cout << fixed << setprecision(6) << search() << '\n';
}