#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 2010;

vector<pii> G[N];
int n, m, s, dis[N];

void dijks()
{
    queue<int> qd, qu, qlif; //d, u, lif;
    qd.push(0), qu.push(s), qlif.push(0);
    memset(dis, -1, sizeof(dis));
    dis[s] = 0;
    while (!qd.empty())
    {
        int d=qd.front(), u=qu.front(), lif=qlif.front();
        qd.pop(), qu.pop(), qlif.pop();
        for (auto e: G[u])
        {
            int v=e.ss, w=e.ff;
            if (dis[v]==-1 || dis[v] >= (d+w)*(lif+1))
            {
                dis[v] = (d+w)*(lif+1);
                qd.push(d+w);
                qu.push(v);
                qlif.push(lif+1);
            }
        }
    }
    
}

signed main()
{
    haaachamachama
    cin >> n >> m >> s;
    for (int i=0,u,v,w; i<m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back({w,v});
        G[v].push_back({w,u});
    }
    dijks();
    rep(i,1,n) cout << dis[i] << ' ';
    cout << '\n';
}
/*
鬆弛時為麼無法確認 dp[i] 為 dp[j] 的最小值
比較晚來 -> 深度比較深
成長速率比較快

5 4 1
1 2 1
2 3 1
3 4 1
4 5 1

3 3 1
1 2 1
2 3 2
1 3 5
*/

