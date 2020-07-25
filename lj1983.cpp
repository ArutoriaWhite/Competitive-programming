#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

int adj[N][N];
vector<int> tmp, tmp2;
int ap[N], res, dp[N], n, m;

int f (int i)
{
    if (dp[i]==-1)
    {
        dp[i] = 0;
        for (int v=1; v<=n; v++)
            if (adj[i][v])
                dp[i] = max(dp[i],f(v)+1);
    }
    return dp[i];
}

int main()
{
    Eriri
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    tmp.reserve(N);
    tmp2.reserve(N);
    for (int i=0,k,l,r; i<m; i++)
    {
        l = N, r = 0;
        memset(ap,0,sizeof(ap));
        tmp.clear();
        tmp2.clear();
        cin >> k;
        for (int j=0,x; j<k; j++)
        {
            cin >> x;
            ap[x] = 1;
            l = min(l,x);
            r = max(r,x);
        }
        for (int j=l; j<=r; j++)
            (ap[j]? tmp : tmp2).push_back(j);
        for (auto u: tmp)
            for (auto v: tmp2)
                adj[u][v] = 1;
    }
    for (int i=1; i<=n; i++)
        res = max(res,f(i));
    cout << res+1 << '\n';
}