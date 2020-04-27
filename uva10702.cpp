#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 110, M = 1010;

int n, s, e, k;
int w[N][N], dp[N][M], avai[N][M], used[N][M], isend[N];

inline void init()
{
    memset(dp,0,sizeof(dp));
    memset(avai,0,sizeof(avai));
    memset(isend,0,sizeof(isend));
    memset(used,0,sizeof(used));
}
void f (int u, int d)
{
    if (used[u][d]) return;
    if (d==k) avai[u][d] = isend[u];
    else
    {
        used[u][d] = 1;
        for (int v=0; v<n; v++)
        {
            if (v!=u)
            {
                f(v,d+1);
                if (avai[v][d+1])
                {
                    avai[u][d] = 1;
                    dp[u][d] = max(dp[u][d], dp[v][d+1] + w[u][v]);
                }
            }
        }
    }
}

signed main()
{
    Eriri
    while (cin >> n >> s >> e >> k && n&&s&&e&&k)
    {
        init();
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> w[i][j];
        for (int i=0,x; i<e; i++)
            cin >> x, isend[x-1] = 1;
        f(s-1,0);
        cout << dp[s-1][0] << '\n';
    }
}