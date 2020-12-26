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
const int N = 14;

int ans, a[N][N], n;

void dfs (int row, int sum, int visa, int visb, int visc)
{
    if (row > n)
    {
        ans = max(ans, sum);
        return;
    }
    visb<<=1, visc>>=1;
    rep(i,1,n)
    {
        if ((visa|visb|visc)&(1<<i)) continue;
        dfs(row+1,sum+a[row][i],visa|(1<<i),visb|(1<<i),visc|(1<<i));
    }
    dfs(row+1,sum,visa,visb,visc);
}

signed main()
{
    cin >> n;
    rep(i,1,n)
        rep(j,1,n)
            cin >> a[i][j];
    dfs(1,0,0,0,0);
    cout << ans << '\n';
}
