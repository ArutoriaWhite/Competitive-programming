#include<iostream>
#include<memory.h>
using namespace std;
const int N = 8, M = 1e8;

int jump[8][2] = { {1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {2,-1}, {-2,1}, {-2,-1} };
int qx[M], qy[M], qd[M], vis[N][N], t=0, f, r;

inline void init()
{
    f = r = 0;
    t++;
}

inline bool canGo (int x, int y)
{
    return 0<=x&&x<N && 0<=y&&y<N && vis[x][y]<t;
}

inline int bfs (int rx, int ry, int ex, int ey)
{
    qx[r] = rx, qy[r] = ry, qd[r]=0, r++;
    while (f<r)
    {
        int ux = qx[f], uy = qy[f], d = qd[f]; f++;
        if (ux == ex && uy == ey) return d;
        for (int i=0; i<8; i++)
        {
            int vx = jump[i][0]+ux, vy = jump[i][1]+uy;
            if (!canGo(vx,vy)) continue;
            vis[vx][vy] = t;
            qx[r] = vx, qy[r] = vy, qd[r] = d+1, r++;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string rt, end;
    while (cin >> rt >> end)
    {
        init();
        cout << "To get from " << rt << " to " << end << " takes "
             << bfs( rt[0]-'a', rt[1]-'0'-1, end[0]-'a', end[1]-'0'-1)
             << " knight moves.\n";
    }
}
    