#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 50;

set<int> apr;
int vis[N], cnt[N][N], n;
string s;
inline void init()
{
    apr.clear();
    memset(vis,0,sizeof(vis));
    memset(cnt,0,sizeof(cnt));
}
void dfs (int u)
{
    vis[u] = 1;
    for (int i=0; i<N; i++)
        if (cnt[u][i] && !vis[i]) dfs(i);
}
inline bool all_vis()
{
    for (auto ele: apr)
        if (!vis[ele]) return 0;
    return 1;
}
inline bool io_sam()
{
    for (int i=0; i<N; i++)
    {
        int in = 0, out = 0;
        for (int j=0; j<N; j++)
            in += cnt[j][i];
        for (int j=0; j<N; j++)
            out += cnt[i][j];
        if (in != out) return 0;
    }
    return 1;
}

int main()
{
    Eriri
    while (cin >> n && n)
    {
        init();
        for (int i=0,u,v; i<n; i++)
        {
            cin >> s, u = s[0]-'a', v = s.back()-'a';
            cnt[u][v]++;
            apr.insert(u);
            apr.insert(v);
        }
        dfs(*apr.begin());
        if (all_vis() && io_sam()) cout << "OK\n";
        else cout << "NG\n";
    }
}
/*
5
apple
young
grandpa
lazy
evil
7
apple
young
grandpa
lazy
evil
add
date
0
*/