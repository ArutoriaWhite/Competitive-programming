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
const int N = 210;

vector<int> G[N], Gt[N], st;
int sccid[N], sccin[N], sccout[N], scc, vis[N];
int n;

void dfs (vector<int> *adj, int u, int k=0)
{
    vis[u] = 1;
    sccid[u] = k;
    for (auto v: adj[u])
    {
        if (vis[v] && sccid[v]!=k)
        {
            sccin[sccid[u]]++;
            sccout[sccid[v]]++;
        }
        if (vis[v]) continue;
        dfs(adj,v,k);
    }
    if (adj==G)
    {
        st.push_back(u);
    }
}
void kosaraju()
{
    rep(i,1,n)
        if (!vis[i])
            dfs(G,i);
    mem(vis,0);
    while (!st.empty())
    {
        int x = st.back(); st.pop_back();
        if (!vis[x])
            dfs(Gt,x,++scc);
    }
}

signed main()
{
    cin >> n;
    rep(i,1,n)
    {
        int x;
        while (cin >> x && x)
        {
            G[i].pb(x);
            Gt[x].pb(i);
        }
    }
    kosaraju();
    int out0=0, in0=0;
    rep(i,1,scc)
    {
        if (sccin[i]==0) in0++;
        if (sccout[i]==0) out0++;
    }
    if (scc==1) cout << 1 << '\n' << 0 << '\n';
    else
    {
        cout << in0 << '\n';
        cout << max(in0,out0) << '\n';
    }
    ////////////////////////////
    cout << max(in0,1LL) << '\n';
    cout << max(in0,out0) << '\n';
}