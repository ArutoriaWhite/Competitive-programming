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
const int N = 110;

int a[N][N], vis[N][N], m, n;
int sh[5][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int legal (int x, int y)
{
    return 1<=x && x<=m && 1<=y && y<=n && !vis[x][y];
}

signed main()
{
    cin >> m >> n;
    rep(i,1,m)
        rep(j,1,n) 
            cin >> a[i][j];
    int ci=1, cj=1;
    rep(i,1,m)
        rep(j,1,n)
            if (a[i][j] < a[ci][cj])
                ci = i, cj = j;
    int sum=0;
    while (1)
    {
        sum += a[ci][cj];
        vis[ci][cj] = 1;
        int ni=-1, nj=-1;
        rep(i,0,3)
        {
            int ti = ci+sh[i][0];
            int tj = cj+sh[i][1];
            if (legal(ti,tj) && (ni<0 || a[ti][tj]<a[ni][nj]))
                ni = ti, nj = tj;
        }
        ci = ni, cj = nj;
        if (ni < 0) break;
    }
    cout << sum << '\n';
}