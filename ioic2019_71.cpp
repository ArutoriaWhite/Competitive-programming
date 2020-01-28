#include <iostream>
#include <bitset>
#define DE cout << " ::"
using namespace std;
const int N = 1e4+10;

bitset<N> adj[N], colo, vis;
long long n, m;

bool dfs (int u, int p)
{
    vis[u] = 1;
    for (int i=1; i<=n; i++)
    {
        if (i==u || !adj[u][i]) continue;
        if (!vis[i])
        {
            colo[i] = ~colo[u];
            if (!dfs(i,u)) return 0;
        }        
        if (colo[i]==colo[u]) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;

    if (((n*n-n)/2)-m > (n*n)/4)
    {
        cout << "No\n";
        return 0;
    }

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            adj[i].set();
    for (int i=0,x,y; i<m; i++)
    {
        cin >> x >> y;
        adj[x].flip(y), adj[y].flip(x);
    }
    
    bool flag=1;
    for (int i=1; i<=n; i++)
    {
        if (!vis[i])
        {
            colo[i] = 1;
            if (!dfs(i,-1))
            {
                flag=0;
                break;
            }
        }
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
}