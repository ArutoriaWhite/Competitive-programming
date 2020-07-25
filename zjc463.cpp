#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

vector<int> adj[N];
int ind[N], n, h[N], ans, rt;

void dfs (int u)
{
    for (auto v: adj[u])
        dfs(v), h[u] = max(h[u], h[v]+1);
    ans += h[u];
}

signed main()
{
    Eriri
    cin >> n;
    for (int i=1,k; i<=n; i++)
    {
        cin >> k;
        for (int j=1,v; j<=k; j++)
            cin >> v, adj[i].push_back(v), ind[v]++;
            
    }
    for (int i=1; i<=n; i++)
    {
        if (!ind[i])
        {
            rt = i;
            break;
        }
    }
    dfs(rt);
    cout << rt << '\n' << ans << '\n';
}