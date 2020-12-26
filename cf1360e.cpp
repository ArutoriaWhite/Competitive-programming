#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 100;

int t, n, ans, u, used[N][N];
string G[N];
queue<int> qx, qy;

void bfs ()
{
    u++;
    while (!qx.empty())
    {
        int x = qx.front(), y=qy.front();
        qx.pop(), qy.pop();
        if (x<0 || y<0) continue;
        if (used[x][y]==u) continue;
        if (G[x][y]=='0') continue;
        used[x][y] = u;
        qx.push(x), qy.push(y-1);
        qx.push(x-1), qy.push(y);
    }
/*     for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << (used[i][j]==u? 1:0);
        cout << '\n';
    }
    cout << '\n'; */
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (used[i][j]<u&&G[i][j]=='1')
                return;
    ans=1;
}

signed main()
{
    exploootion
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> G[i];
        ans = 0;
        for (int i=0; i<n; i++)
        {
            qx.push(n-1), qy.push(i);
            qx.push(i), qy.push(n-1);
        }
        bfs();
        cout << (ans? "YES":"NO") << '\n';
    }
}