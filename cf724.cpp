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

int n, m, k;
int xx, yy, g;
int exgcd (int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int nx, ny, g;
    g = exgcd(b,a%b,nx,ny);
    x = ny;
    y = nx - a/b*ny;
    return g;
}
int sol (int i, int j)
{
    if ((j-i)%g != 0)
        return 9e18;
    int p = (j-i)/g*xx;
    int q = (j-i)/g*yy;
    int l = n*m/__gcd(n,m);
    p = (p%(l/n)+(l/n))%(l/n);
    q = (q%(l/m)+(l/m))%(l/m);
    if (p*2*n+i<=0 || q*2*m+j<=0)
        return 9e18;
    return p*2*n+i;
}

signed main()
{
    ShinraTensei
    cin >> n >> m >> k;
    g = exgcd(2*n,-2*m,xx,yy);
    rep(i,1,k)
    {
        int x, y;
        cin >> x >> y;
        int ans = 9e18;
        ans = min(sol(x,y), ans);
        ans = min(sol(x,-y), ans);
        ans = min(sol(-x,y), ans);
        ans = min(sol(-x,-y), ans);
        cout << (ans==9e18? -1:ans) << '\n';
    } 
}