#include<iostream>
using namespace std;
const int N=1e3+10;

string G[N];
int mX, mY;
int wal[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int qx[M], qy[M], f, r, vis[N][N], t;

inline bool can (int x, int y)
{
    return 0<=x&&x<mX && 0<=y&&y<mY && vis[vy][vx]<t && G[vx][vy]=='.';
}

inline void bfs (int rtx, int rty)
{
    qx[r] = rtx, qy[r] = rty, r++;
    while (f<r)
    {
        int ux=qx[f], uy=qy[f]; f++;
        for (int i=0; i<4; i++)
        {
            int vx=ux+walk[i][0], vy=uy+walk[i][1];
            if (!can(vx,vy)) continue;
            qx[r]=vx, qy[r]=vy, r++;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (t=1; t<=T; t++)
    {
        f=r=0;
        cin >> mY >> mX;
        for (int y=0; y<mY; y++)
            cin >> G[y];

        int res=0;
        for (int y=0; y<mY; y++)
        {
            for (int x=0; x<mX; x++)
            {
                if (vis[y][x]>=t) continue;
                bfs (x,y);
                res++;
            }
        }
        cout << res << '\n';
    }
}

