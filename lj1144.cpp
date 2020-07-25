#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10, M = 100003;

vector<int> adj[N];
int n, m, d[N], cnt[N];
queue<int> q;

inline void bfs()
{
    memset(d,-1,sizeof(d));
    q.push(1);
    d[1] = 0, cnt[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v: adj[u])
        {
            if (d[v]<0)
            {
                d[v] = d[u]+1;
                cnt[v] = cnt[u];
                q.push(v);
            }
            else if (d[v]>d[u])
                cnt[v] = (cnt[v]+cnt[u])%M;
        }
    }
}

int main()
{
    Eriri
    cin >> n >> m;
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    for (int i=1; i<=n; i++)
        cout << cnt[i] << '\n';
}