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
const int N = 2e6+10;

int w[N], n, m, t;
vector<int> G[N];

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        mem(w,0);
        cin >> n >> m;
        rep(i,1,n) cin >> w[i], G[i].clear();
        rep(i,2,n)
        {
            int x, y;
            cin >> x >> y;
            G[x].pb(y);
            G[y].pb(x);
        }
        //////
        int u=0;
        rep(i,1,n)
            if (w[i] > w[u])
                u = i;
        int v=0;
        for (auto i: G[u])
            if (w[i] > w[v])
                v = i;
        if (v==0)
        {
            cout << u << '\n';
        }
        else if (w[u]-w[v] > m)
        {
            cout << u << '\n';
        }
        else
        {
            m -= w[u]-w[v];
            if (u>v) swap(u,v);
            if (m&1)
            {
                cout << v << '\n';
            }
            else
            {
                cout << u << '\n';
            }
        }
    }
}
/*
1
3 1
1 1 2
1 3
2 3

1
3 2
1 1 2
1 3
2 3
*/