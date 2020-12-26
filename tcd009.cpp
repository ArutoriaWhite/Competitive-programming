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
const int N = 15;

int n, m;
int a[N][N], res = 9e18;

int rval (int row, int l, int r)
{
    int c[2]={};
    rep(i,l,r)
        c[a[row][i]]++;
    return min(c[0], c[1]);
}
int cval (int col, int u, int d)
{
    int c[2]={};
    rep(i,u,d)
        c[a[i][col]]++;
    return min(c[0], c[1]);
}

void dfs (int u, int d, int l, int r, int sum)
{
    if (sum > res) return;
    if (u>d || l>r)
    {
        res = sum;
        return;
    }

    dfs(u+1,d,l,r,sum+rval(u,l,r));
    dfs(u,d-1,l,r,sum+rval(d,l,r));
    dfs(u,d,l+1,r,sum+cval(l,u,d));
    dfs(u,d,l,r-1,sum+cval(r,u,d));
}

signed main()
{
    cin >> m >> n;
    rep(i,1,m)
        rep(j,1,n)
            cin >> a[i][j];
    dfs(1,m,1,n,0);
    cout << res << '\n';
}