#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10, M = 2e5+10;

struct Edg {int v, w, nx;} e[M<<1];
int h[N], cnt;
inline void add (int u, int v, int w){
    cnt++, e[cnt] = {v,w,h[u]}, h[u] = cnt;
}

int d[N], n, m;
priority_queue<Pii,vector<Pii>,greater<Pii>> pq;
inline int dijks()
{
    pq.push({0,1});
    for (int i=2; i<=n; i++)
        d[i] = 1e17;
    while (!pq.empty())
    {
        int dis = pq.top().F, u = pq.top().S;
        pq.pop();
        if (dis > d[u]) continue;
        for (int i=h[u]; i; i=e[i].nx)
        {
            if (d[e[i].v] > e[i].w+dis)
            {
                pq.push({e[i].w+dis, e[i].v});
                d[e[i].v] = e[i].w + dis;
            }
        }
    }
    int res = 0;
    for (int i=1; i<=n; i++)
        res = max( res, d[i]);
    return res;
}

signed main()
{
    Eriri
    cin >> n >> m;
    for (int i=0,u,v,w; i<m; i++)
    {
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    cout << dijks() << '\n';
}
