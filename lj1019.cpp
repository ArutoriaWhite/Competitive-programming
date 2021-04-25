#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

const int N = 50;

string s[N];
int n;
char op;
int vis[N];
vector<pii> G[N]; // G[i]: {w,j} string i connect by w to j

int adj (int i, int j)
{
    for (int len=1; len<min(s[i].size(), s[j].size()); len++)
    {
        int flag = 1;
        for (int x=s[i].size()-len,y=0; y<len; x++,y++)
        {
            if (s[i][x] != s[j][y])
            {
                flag = 0;
                break;
            }
        }
        if (flag) return len;
    }
    return -1;
}
int dfs (int i) // return max length of string (include i), status: now on i, vis[] visited
{
    int ans = 0;
    vis[i] = 1;

    for (auto e: G[i])
    {
        int w = e.ff;
        int v = e.ss;
        if (vis[v]) continue;
        ans = max(ans, dfs(v)-w);
    }

    vis[i] = 0;
    return ans+s[i].size();
}

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> s[i];
    cin >> op;

    rep(i,1,n) s[i+n] = s[i];
    n*=2;

    rep(i,1,n)
    {
        rep(j,1,n)
        {
            if (i == j) continue;
            int w = adj(i,j);
            if (w < 0) continue;
            G[i].pb({w,j});
        }
    }

    int ans = 0;
    rep(i,1,n)
        if (s[i][0] == op)
            ans = max(ans, dfs(i));

    cout << ans << '\n';
}