#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e5+10;

struct Edge {int u, v, w; } edges[N];
int res, p[N], k, n, m;
inline int fp (int x) { return (p[x]==-1? x : fp(p[x])); }
inline void U (int u, int v) { p[fp(u)] = fp(v); }
inline void krus()
{
    memset(p,-1,sizeof(p));
    sort(edges,edges+m,[](Edge &a, Edge &b){ return a.w < b.w; });
    for (int i=0; i<m; i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (fp(u) == fp(v)) continue;
        k++;
        U(u,v);
        res += w;
    }
}
int main()
{
    cin >> n >> m;
    for (int i=0; i<m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    krus();
    cout << (k==n-1? res : -1) << '\n';
}
