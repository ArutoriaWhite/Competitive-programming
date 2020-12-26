#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1010, M = 1e6+10;

int n, m;
struct Edg {int u, v, w;} e[M];
vector<Edg> et;
vector<pii> G[N];
int p[N];

int find (int u){ return (p[u]==u? u : p[u]=find(p[u])); }
int krus()
{
    rep(i, 0, n) p[i] = i;
    sort(e+1, e+m+1, [](Edg x, Edg y){return x.w<y.w;});
    int res=0, cnt=0;
    rep(i, 1, m)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if (find(u) == find(v)){ et.push_back(e[i]); continue; }
        p[find(u)] = find(v);
        res += w;
        cnt++;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    return (cnt==n-1? res : -1);
}

int pa[N][30], val[N][30], d[N];
void dfs (int u)
{
    rep(i, 1, 29)
    {
        pa[u][i] = pa[pa[u][i-1]][i-1];
        val[u][i] = max(val[u][i-1], val[pa[u][i-1]][i-1]);
    }
    for (auto ee: G[u])
    {
        if (ee.S != pa[u][0])
        {
            pa[ee.S][0] = u;
            val[ee.S][0] = ee.F;
            d[ee.S] = d[u]+1;
            dfs(ee.S);
        }
    }
}
int query (int a, int b)
{
    int res = 0;
    if (d[a] < d[b]) swap(a, b);
    for (int t=d[a]-d[b],i=0; t; t>>=1,i++)
        if (t&1) res = max(res, val[a][i]), a = pa[a][i];
    if (a == b) return res;
    int s = 29;
    while (s >= 0)
    {
        if (pa[a][s] != pa[b][s])
        {
            res = max(res, val[a][s]);
            res = max(res, val[b][s]);
            a = pa[a][s], b = pa[b][s];
        }
        else s--;
    }
    res = max(res, val[a][0]);
    res = max(res, val[b][0]);
    return res;
}

signed main()
{
    XinAi
    cin >> n >> m;
    rep(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
    int mst = krus();
    if (mst == -1){ cout << -1 << ' ' << -1 << '\n'; return 0; }
    
    //print(1, 0), de(mst), dd;
    
    dfs(1);
    int res = -1;
    for (auto ee: et)
    {
        int owo = mst - query(ee.u, ee.v) + ee.w;
        if (res==-1 || owo<res) res = owo;
    }
    cout << mst << ' ' << res << '\n';
}