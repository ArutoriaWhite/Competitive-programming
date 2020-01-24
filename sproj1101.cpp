#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
const int N = 1e5+10;

vector<int> adj[N];
int colo[N], n, m;

int dfs (int u, int p)
{
    for (auto v: adj[u])
    {
        if (v == p) continue;
        if (colo[v]*colo[u]==1) return 0;
        if (colo[v]==0)
        {
            colo[v] = -colo[u];
            if (!dfs(v,u)) return 0;1
        }
    }   
    return 1;
}
inline void init()
{
    memset(colo,0,sizeof(colo));
    colo[0] = 1;
    for (int i=0; i<N; i++)
        adj[i].clear();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> n && n!=0)
    {
        init();
        cin >> m;
        for (int i=0,a,b; i<m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if (dfs(0,-1)) cout << "NORMAL.\n";
        else cout << "RAINBOW.\n";
    }
}
