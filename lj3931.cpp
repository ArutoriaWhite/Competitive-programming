#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
typedef pair<int,int> pii;
/*
�y�����l���̤j�y = �ڬy��o�̬���̤p���v�P�~�`�I���̤p���v�̪���� min
���@ dp[i]: �q�o���I���U�y���̤p�y�q
*/

const int N = 1e5+10;
vector<pii> G[N]; // {capacity, i};
int n, rt;

int dfs (int u = rt, int p = 0) // return max flow to leaf
{
    if (G[u].size() == 1 && u!=rt)
        return 9e18;
    int f = 0;
    for (auto e: G[u])
    {
        int w = e.ff;
        int v = e.ss;
        if (v == p) continue;
        int nf = min(w, dfs(v,u));
        f += nf;
    }
    return f;
}

signed main()
{
    pui
    cin >> n >> rt;
    rep(i,2,n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w,v});
        G[v].pb({w,u});
    }
    cout << dfs() << '\n';
}
