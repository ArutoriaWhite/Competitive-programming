#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

vector<int> G1[100], G2[100];
vector<Pii> v1, v2;
int vis[100], n;
string s;

inline void init()
{
    for (int i=0; i<100; i++)
        G1[i].clear(), G2[i].clear();
    v1.clear(), v2.clear();
}

void dfs1 (int u, int p)
{
    vis[u] = 1;
    for (auto v: G1[u])
        if (v!=p && !vis[v])
            v1.push_back({u,v}), dfs1(v,u);
}
void dfs2 (int u, int p)
{
    vis[u] = 1;
    for (auto v: G2[u])
        if (v!=p && !vis[v])
            v2.push_back({v,u}), dfs2(v,u);
}
inline bool same ()
{
    if (v1.size()!=v2.size()) return 0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());    
    for (int i=0,k=v1.size(); i<k; i++)
        if (v1[i] != v2[i]) return 0;
    return 1;
}
inline void print()
{
    for (auto x: v1) de(x.F), de(x.S);
    dend;
    for (auto x: v2) de(x.F), de(x.S);
    dend;
}

int main()
{
    Eriri;
    while (cin >> n && n)
    {
        init();
        int i, u, v;
        for (i=0; i<n; i++)
        {
            cin >> s, u = s[0]-'a', v = s.back()-'a';
            G1[u].push_back(v);
            G2[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));
        dfs1(u,-1);
        memset(vis,0,sizeof(vis));
        dfs2(u,-1);
        cout << (same()? "OK" : "NG") << '\n';
        print();
    }
}