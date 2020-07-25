#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e4+10;

struct Edg { int v, nx; } e[N<<1];
int n, h[N], cnt, dis[N], sz[N], res;

inline void add (int u, int v) {
    cnt++, e[cnt] = {v,h[u]}, h[u] = cnt;
}
void dfs1 (int u, int p) {
    sz[u] = 1;
    for (int i=h[u]; i; i=e[i].nx) {
        if (e[i].v != p) {
            dfs1(e[i].v,u);
            sz[u] += sz[e[i].v];
            dis[u] += sz[e[i].v]+dis[e[i].v];
        }
    }
}
void dfs2 (int u, int p) {
    if (u != 1)
        dis[u] += dis[p] - dis[u] - sz[u] + sz[1] - sz[u];
    for (int i=h[u]; i; i=e[i].nx)
        if (e[i].v != p)
            dfs2(e[i].v,u);
}

int main() {
    Eriri
    cin >> n;
    for (int i=0,u,v; i<n-1; i++) {
        cin >> u >> v;
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i=1; i<=n; i++)
        if (res==0 || dis[i] < dis[res])
            res = i;
    cout << res << ' ' << dis[res] << '\n';
}