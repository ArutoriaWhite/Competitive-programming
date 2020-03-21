#include <bits/stdc++.h>
#define akiyama ios::sync_with_stdio(0), cin.tie(0);
#define all(x) x.begin(), x.end()
#define exi(x,s) (s.find(x) != x.end())
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define uset unordered_set
#define umap unordered_map
#define de(x) cout << #x << '=' << x << ", "
#define dend cout << "\n"
typedef long long ll;
using namespace std;
const int INF=0x7f7f7f7f, N = 1e5+10;

vector<int> adj[N];
int h1[N], h2[N], max_son[N], limd, n;

inline void upd (int u, int v, int h)
{
    if (h>h1[u])
        h2[u] = h1[u], h1[u] = h, max_son[u] = v;
    else if (h>h2[u])
        h2[u] = h;
}

void dfs_h (int u, int p)
{
    upd(u,0,1);
    for (auto v: adj[u])
    {
        if (v==p) continue;
        dfs_h(v,u);
        upd(u,v,h1[v]+1);
    }
}
void dfs_hfp (int u, int p)
{
    if (u!=1)
    {
        if (max_son[p] != u) upd(u,p,h1[p]+1);
        else  upd(u,p,h2[p]+1);
    }
    for (auto v: adj[u])
        if (v!=p) dfs_hfp(v,u);
}
inline void print (int u, int p)
{
	cout << u << " \n"[(--n)==0];
    for (auto v: adj[u])
        if (v!=p)
            print(v,u);
}

int main()
{
    akiyama;
    cin >> n >> limd;
    for (int i=0,a,b; i<n-1; i++)
    {
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    for (auto &v: adj) sort(all(v));
    dfs_h(1,0);
    dfs_hfp(1,0);

    int flag=0;
    for (int i=1; i<=n; i++)
        if (h1[i]<limd)
        {
            print(i,0), cout << '\n';
            flag=1;
            break;
        }
    if (!flag) cout << -1 << '\n';
}

