#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

int G[N][N][2], h, w, tow[5][2]={{1,0}, {-1,0}, {0,1}, {0,-1}, {0,0}};

int bfs()
{
    queue<int> qx, qy, qm, qd;
    qx.push(1), qy.push(1), qm.push(0), qd.push(0);
    while (!qx.empty())
    {
        int x=qx.front(), y=qy.front(), mo=qm.front(), dep=qd.front();
        qx.pop(), qy.pop(), qm.pop(), qd.pop();
        if (x==h && y==w) return dep;
        for (int i=0; i<5; i++)
        {
            if (i==4 && mo) continue;
            if (i==4) mo = 1;
            int vx=x+tow[i][0], vy=y+tow[i][1];
            if (vx>h || vx<1 || vy>w || vy<1 || G[vx][vy][mo]) continue;
            G[vx][vy][mo] = 1;
            qx.push(vx), qy.push(vy), qm.push(mo), qd.push(dep+1);
        }
    }
    return -1;
}

signed main()
{
    SakuraMyWife
    cin >> h >> w >> tow[4][0] >> tow[4][1];
    rep(i,1,h)
    {
        rep(j,1,w)
        {
            char c;
            cin >> c;
            G[i][j][0] = c=='#';
            G[i][j][1] = c=='#';
        }
    }
    cout << bfs() << '\n';
}