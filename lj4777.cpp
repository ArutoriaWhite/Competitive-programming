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
const int N = 1e5+10;

int a[N], m[N], n;
int mul (int i, int j, int M)
{
    i = (i%M+M)%M;
    j = (j%M+M)%M;
    int res=0;
    for (; j; j>>=1,i=i*2%M)
        if (j&1)
            res = (res+i)%M;
    return res;
}
// find x, y that ax + by = gcd(a,b) and return gcd(a,b)
// gcd(a,b) = (b,a%b)
// ax + by = bx' + ay' - [a/b]*by'
// 
int exgcd (int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x=1, y=0;
        return a;
    }
    int nx, ny, g;
    g = exgcd(b,a%b,nx,ny);
    x = ny;
    y = nx - a/b*ny;
    return g;
}  
int sol (int a, int b, int c, int M) // find x such that ax + by === c (mod M)
{
    c = (c%M+M)%M;

    int x, y, g;
    g = exgcd(a,b,x,y);
    x = mul(x,c/g,M);
    return x;
}

int crt ()
{
    rep(i,2,n)
    {
        int a1 = a[i-1], m1 = m[i-1];
        int a2 = a[i], m2 = m[i];
        int p = sol(m1,m2,a2-a1,m2);
        int l = m1/__gcd(m1,m2)*m2;
        a[i] = (a1 + mul(m1,p,l))%l;
        m[i] = l;
    }
    return a[n];
}

signed main()
{
    cin >> n;
    rep(i,1,n)
        cin >> m[i] >> a[i];
    cout << crt() << '\n';
}