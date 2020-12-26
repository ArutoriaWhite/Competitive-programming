#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

vector<int> adj[N];
int vis[N], t, p, q, k, match[N], cnt;

int dfs (int u)
{
    for (auto v: adj[u])
    {
        if (vis[v] >= cnt) continue;
        vis[v] = cnt;
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}
int konig ()
{
    int res = 0;
    for (int i=1; i<=p; i++)
    {
        cnt++;
        res += dfs(i);
    }
    return res;
}

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> p >> q >> k;
        for (int i=0; i<=p+q; i++)
            adj[i].clear(), match[i] = 0;
        for (int i=1,x,y; i<=k; i++)
        {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        cout << konig() << '\n';
    }
}