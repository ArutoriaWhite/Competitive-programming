#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10, Q = 1e4+10;
/*
sort edge
sort query
add egde (dsu Union, now ans -= set A + set B, += new set
*/
struct Que {int w, id;} qq[Q];
struct Edg {int u, v, w;} edg[N];
int n, m, q, ans[Q], p[N], sz[N];

int find (int x){ return (x==p[x]? x : p[x]=find(p[x]));};
void U (int u, int v)
{
    u=find(u), v=find(v);
    sz[u] += sz[v];
    p[v]=u;
}

signed main()
{
    XinAi
    cin >> n >> m >> q;
    rep(i,1,m) cin >> edg[i].u >> edg[i].v >> edg[i].w;
    rep(i,1,q) cin >> qq[i].w, qq[i].id=i;
    sort(edg+1,edg+1+m,[](Edg i, Edg j){return i.w<j.w;});
    sort(qq+1,qq+1+q,[](Que i, Que j){return i.w<j.w;});
    
    rep(i,1,n) p[i]=i, sz[i]=1;
    int i=1, res=0;
    rep(j,1,q)
    {
        for (int lim=qq[j].w; i<=m&&edg[i].w<=lim; i++)
        {
            int u=find(edg[i].u), v=find(edg[i].v), w=edg[i].w;
            if (u == v) continue;
            else
            {
                res -= sz[u]*(sz[u]-1);
                res -= sz[v]*(sz[v]-1);
                U(u,v);
                res += sz[find(u)]*(sz[find(u)]-1);
            }
        }
        ans[qq[j].id] = res;
    }
    rep(i,1,q) cout << ans[i] << '\n';
}
