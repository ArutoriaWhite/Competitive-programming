#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define dis(i,j) sqrt( pow((sx[i]-sy[i]),2) + pow((dx[i]-dy[i]),2) )
using namespace std;
typedef pair<int,int> Pii;
const int N = 500;

int n, m, s, v;
int rt = 250, ed = 300, vis[N];
double sx[N], sy[N], dx[N], dy[N];
vector<int> adj[N], w, to;

void add (int u, int v, int x)
{
    adj[u].push_back(w.size());
    w.push_back(x);
    to.push_back(v);
}
int dfs (int u, int f)
{
    if (u == ed) return f;
    vis[u] = 1;
    for (auto v: adj[u])
    {
        if (w[v] <= 0 || vis[to[v]]) continue;
        int tf = dfs(to[v],min(f,w[v]));
        if (tf > 0)
        {
            w[v] -= tf;
            w[v^1] += tf;
            return tf;
        }
    }
    return 0;
}
int flow ()
{
    int res = 0, f;
    while (1)
    {
        memset(vis,0,sizeof(vis));
        f = dfs(rt,INT_MAX);
        if (f <= 0) break;
        res += f;
    }
    return res;
}

int main()
{
    while (cin >> n >> m >> s >> v)
    {
        for (int i=0; i<n; i++)
            cin >> sx[i] >> sy[i];
        for (int i=0; i<m; i++)
            cin >> dx[i] >> dy[i];
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (dis(i,j)/v <= s)
                    add(i,j+n,1), add(j+n,i,0);
        for (int i=0; i<n; i++)
            add(rt,i,1), add(i,rt,0);
        for (int i=0; i<m; i++)
            add(i+n,ed,1), add(ed,i+n,0);
        cout << n-flow() << '\n';
    }
}