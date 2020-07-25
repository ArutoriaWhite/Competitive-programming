#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

vector<int> adj[N];
int typ[N], n, m; // H=1, G=2
string s;
char c;

struct Lca {
    int p[N][30], cow[N][30][3], d[N];
    void dfs (int u, int fa) {
        p[u][0] = fa;
        cow[u][0][1] = (typ[u]==1 || typ[fa]==1);
        cow[u][0][2] = (typ[u]==2 || typ[fa]==2);
        for (int j=1; j<30; j++) {
            p[u][j] = p[ p[u][j-1] ][j-1];
            cow[u][j][1] |= (cow[u][j-1][1] || cow[p[u][j-1]][j-1][1]);
            cow[u][j][2] |= (cow[u][j-1][2] || cow[p[u][j-1]][j-1][2]);
        }
        for (auto v: adj[u]) {
            if (v != fa) {
                d[v] = d[u] + 1;
                dfs(v,u);
            }
        }
    }
    int query (int u, int v, int w) {
        if (d[u] > d[v]) swap(u,v);
        for (int tmp=d[v]-d[u],j=0; tmp; tmp>>=1,j++) {
            if (tmp&1) {
                if (cow[v][j][w]) return 1;
                v = p[v][j];
            }
        }
        if (u == v) {
            if (typ[u]==w || typ[v]==w) return 1;
            return 0;
        }
        for (int i=29; i>=0; i--) {
            if (p[u][i] != p[v][i]) {
                if (cow[u][i][w] || cow[v][i][w])
                    return 1;
                u = p[u][i], v = p[v][i];
            }
        }
        if (cow[u][0][w] || cow[v][0][w])
            return 1;
        return 0;
    }
} lca;

int main() {
    Eriri
    cin >> n >> m >> s;
    for (int i=1; i<=n; i++)
        typ[i] = (s[i-1]=='H'? 1 : 2);
    for (int i=0,u,v; i<n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    lca.dfs(1,0);
    for (int i=0,u,v; i<m; i++) {
        cin >> u >> v >> c;
        cout << lca.query(u,v,(c=='H'? 1 : 2));
    }
    cout << '\n';
}
/*
8 5
GHHHHGHG
1 2
2 3
3 4
4 5
5 6
2 7
1 8
*/