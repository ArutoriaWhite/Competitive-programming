#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 110, M = 1000007;

int a[N][N], dp[N][N], vis[N][N], n, t, T, rx, ry;
char c;

inline bool can (int x, int y)
{
    return 0<=x&&x<n && 0<=y&&y<n && !a[x][y];
}
int f (int x, int y)
{
    if (y==0) return 1;
    if (vis[x][y] < t)
    {
        vis[x][y] = t;
        if (can(x-1,y-1)) dp[x][y] = ( dp[x][y]+f(x-1,y-1) )%M;
        if (can(x+1,y-1)) dp[x][y] = ( dp[x][y]+f(x+1,y-1) )%M;
        if (!can(x-1,y-1) && can(x-2,y-2)) dp[x][y] = ( dp[x][y]+f(x-2,y-2) )%M;
        if (!can(x+1,y-1) && can(x+2,y-2)) dp[x][y] = ( dp[x][y]+f(x+2,y-2) )%M;
    }
    return dp[x][y];
}

int main()
{
    Eriri
    cin >> T;
    while (t++<T)
    {
        memset(dp,0,sizeof(dp));
        cin >> n;
        for (int y=0; y<n; y++)
        {
            for (int x=0; x<n; x++)
            {
                cin >> c, a[x][y] = (c=='B');
                if (c=='W') rx = x, ry = y;
            }            
        }
        cout << "Case " << t << ": " << f(rx,ry) << "\n";
    }
}