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
const int N = 1e4+10;

int n, m, q;
vector<pii> G[N];
vector<int> st;
int bid[N], d[N], low[N], tstamp, bcc;

void dfs (int u, int eid)
{
    d[u] = low[u] = ++tstamp;
    st.push_back(u);
    for (auto e: G[u])
    {
        if (eid == e.F) continue;
        if (!d[e.S])
            dfs(e.S,e.F), low[u]=min(low[u],low[e.S]);
        else
            low[u] = min(low[u], d[e.S]);
    }
    if (low[u] == d[u])
    {
        int x; bcc++;
        do{
            x=st.back(); st.pop_back();
            bid[x] = bcc;
        }while (x!=u);
    }
}
signed main()
{
    XinAi
    cin >> n >> m >> q;
    for (int i=1,u,v; i<=m; i++)
    {
        cin >> u >> v;
        G[u].push_back({i,v});
        G[v].push_back({i,u});
    }
    rep(u, 0, n-1) if(!d[u]) dfs(u,0);
    for (int i=1,u,v; i<=q; i++)
    {
        cin >> u >> v;
        cout << (bid[u]==bid[v]? "Y":"N") << '\n';
    }
}
/*
5 5 2
0 3
0 1
1 4
1 2
4 2
4 3
4 1
*/
