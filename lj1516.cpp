#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int __int128
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define MOD(a,b) (((a%b)+b)%b)
using namespace std;
typedef pair<int,int> pii;
/*
已知
a 點在 x
b 點在 y
a 每秒負跳 m 格
b 每秒負跳 n 格
位置會 +L mod L
跳幾下後 a b 重疊

設跳 t 下
a position = x - t*m
b position = y - t*n

x+t*m === y+t*n (mod L)
t*n - t*m === x-y (mod L)
t(n-m) === x-y (mod L)

找 t 的最小正整數解
t*(s2-s1) + s*L === pos2-pos1 (mod L)
l = lcm(s2-s1, L)
(t+lk/(s2-s1))*(s2-s1) + 
*/

int s1, s2, pos1, pos2, L;

int exgcd (int a, int b, int &x, int &y) // find x, y such that ax+by==gcd(a,b) then return gcd(a,b)
// gcd(a,b) = gcd(b,a%b)
// ax + by = bx' + ay' - a//b*b*y'
{
    if (b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int g, nx, ny;
    g = exgcd(b,a%b,nx,ny);
    x = ny;
    y = nx - a/b*ny;
    return g;
}

int sol() // find min t answer
{
    int a = MOD(s2-s1,L);
    int b = L;
    int c = MOD(pos1-pos2,L);

    int x, y, g;
    g = exgcd(a,b,x,y);

    if (c%g != 0) return -1;
    x = x/g*c;

    //int l = L/__gcd(s2-s1,L);

    return ((x*(a/g))%(L/g)+(L/g))%(L/g);
}

signed main()
{
    signed a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    pos1 = a, pos2 = b, s1 = c, s2 = d, L = e;
    int ans = sol();
    if (ans < 0) cout << "Impossible\n";
    else cout << ((signed)ans) << '\n';
}