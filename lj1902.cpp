#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

queue<int> qx, qy, qd;
int a[N][N], dis[N][N], mx, my;

void bfs()
{
    for (int x=1; x<=mx; x++)
        qx.push(x), qy.push(1), qd.push(a[x][1]), dis[x][1] = a[x][1];
    while (!qd.empty())
    {
        int x = qx.front(), y = qy.front(), d = qd.front();
        qx.pop(), qy.pop(), qd.pop();
        if (dis[x][y] < d) continue;
        for (int i=-1; i<=1; i++)
        {
            for (int j=-1; j<=1; j++)
            {
                if (!(i||j) || !(!i || !j)) continue;
                int vx = x+i, vy = y+j;
                if (vx<1 || vy<1 || vx>mx || vy>my) continue;
                d = max(d, a[vx][vy]);
                if (d < dis[vx][vy])
                    dis[vx][vy] = d, qx.push(vx), qy.push(vy), qd.push(d);
            }
        }
    }
}

signed main()
{
    XinAi
    cin >> my >> mx;
    for (int y=1; y<=my; y++)
        for (int x=1; x<=mx; x++)
            cin >> a[x][y];
    memset(dis, 0x3f, sizeof(dis));
    bfs();
    int res = 0x3f3f3f3f;
    for (int x=1; x<=mx; x++) res = min(res, dis[x][my-1]);
    cout << res << '\n';
}