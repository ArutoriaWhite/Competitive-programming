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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1010;

vector<Pii> adj1[N], adj2[N];
int dis[N], n, m;
Pq<Pii> q;

inline int qr()
{
    char a=0;int x=0,w=1;
    while(a<'0'||a>'9'){if(a=='-')w=-1;a=getchar();}
    while(a>='0'&&a<='9'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
    return x*w;
}

int dijks (vector<Pii> adj[N])
{
    mem(dis,INF);
    dis[1] = 0;
    q.push({1,0});
    while (!q.empty())
    {
        int u = q.top().fi, d = q.top().se;
        q.pop();
        if (dis[u] < d) continue;
        for (auto e: adj[u])
        {
            if (dis[e.fi] > d+e.se)
            {
                dis[e.fi] = d+e.se;
                q.push({e.fi,dis[e.fi]});
            }
        }
    }
    int res = 0;
    for (int i=2; i<=n; i++)
        res += dis[i];
    return res;
}

int main()
{
    yukari;
    n = qr(), m = qr();
    for (int i=0,u,v,w; i<m; i++)
    {
        u = qr(), v = qr(), w = qr();
        adj1[u].pb({v,w});
        adj2[v].pb({u,w});
    }
    cout << dijks(adj1)+dijks(adj2) << '\n';
}