#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e6+10, LOG = 21;

vector<int> adj[N];
int anc[N][LOG], tin[N], tout[N], t;
int n, q;

inline void dfs (int u, int p, int d)
{
    tin[u] = t++;
    anc[u][0] = p;
    for (int i=1; (1<<i)<=d; i++)
        anc[u][i] = anc[anc[u][i-1]][i-1];
    for (auto v: adj[u])
        dfs(v,u,d+1);
    tout[u] = t++;
}
inline bool isanc (int v, int anc)
{
    if (anc<0) return 1;
    return tin[anc]<tin[v]&&tout[v]<tout[anc];
}
inline int lca (int x, int y)
{
    if (x==y || isanc(x,y)) return y;
    if (isanc(y,x)) return x;
    for (int i=LOG-1; i>=0; i--)
        while (!isanc(y,anc[x][i]))
            x = anc[x][i];
    return anc[x][0];
}
inline void init()
{
    memset(anc,-1,sizeof(anc));
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    cin >> n >> q;
    for (int u=1,p; u<n; u++)
        cin >> p, adj[p].push_back(u);
    dfs(0,-1,0);
    for (int i=0,x,f,res; i<q; i++)
    {
        cin >> x;
        for (int j=0; j<x; j++)
        {
            cin >> f;
            if (j==0) res = f;
            else      res = lca(res,f); 
        }
        cout << res << '\n';
    }
}
/*
6 7
0 0 1 3 1
3 4 5 2
2 3 2
2 4 3
2 4 5
3 4 3 5
1 1
1 4

*/