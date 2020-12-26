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

int rx, ry, cx, cy, mx, my, vis[N][N], d[N][N];
char a[N][N];2

void dfs (int x, int y)
{
    if (x<1 || y<1 || x>mx || y>my || vis[x][y] || a[x][y]=='#') return;
    vis[x][y] = 1;
    dfs(x-1, y), dfs(x, y-1), dfs(x+1, y), dfs(x, y+1);
}
int bfs()
{
    queue<int> qx, qy;
    qx.push(cx), qy.push(cy), d[cx][cy] = 0;
    while (!qx.empty())
    {
        int x = qx.front(), y = qy.front();
        qx.pop(), qy.pop();
        if (vis[x][y]) return d[x][y];
        for (int i=-2; i<=2; i++)
            for (int j=-2; j<=2; j++)
            {
                int vx = x + i, vy = y + j;
                if (vx < 1 || vy < 1 || vx>mx || vy>my || a[vx][vy] == '#') continue;
                if (d[vx][vy] <= d[x][y] + 1) continue;
                d[vx][vy] = d[x][y]+1;
                qx.push(vx);
                qy.push(vy);
            }
    }
    return -1;
}
signed main()
{
    XinAi
    cin >> my >> mx >> ry >> rx >> cy >> cx;
    for (int y=1; y<=my; y++)
        for (int x=1; x<=mx; x++)
            cin >> a[x][y];
    dfs(rx, ry);
    memset(d, 0x3f, sizeof(d)); 
    cout << bfs() << '\n';
}
