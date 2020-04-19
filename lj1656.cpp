#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, M = 5e3+10, N = 200;

int n, m, a, b, r, vis[N], cnt;
vector<int> adj[N];
Pii edges[M], res[M];
queue<int> q;

inline bool bfs (int x, int y)
{
    while (!q.empty()) q.pop();
    mem(vis,0);
    q.push(1), vis[1] = 1, cnt = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto v: adj[u])
            if ((u!=x||v!=y) && (u!=y||v!=x) && (!vis[v]))
                cnt++, vis[v]=1, q.push(v);
    }
    return cnt==n;
}

int main ()
{
    yukari;
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        if (a>b) swap(a,b);
        edges[i] = {a,b};
    }
    for (int i=0; i<m; i++)
        if (!bfs(edges[i].fi,edges[i].se))
            res[r++] = edges[i];
    sort(res,res+r);
    for (int i=0; i<r; i++)
        cout << res[i].fi << ' ' << res[i].se << '\n';
}