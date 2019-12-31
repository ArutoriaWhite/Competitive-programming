#include<iostream>
using namespace std;
const int N=1e3+10, M=1e8;

string G[N];
int wal[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int vis[N][N], t, mX, mY;
int qx[M], qy[M], f, r;

inline bool can (int x, int y)
{
    return 0<=x&&x<mX && 0<=y&&y<mY && vis[y][x]<t && G[y][x]!='#';
}

void bfs (int rx, int ry)
{
    f=r=0;
    qx[r]=rx, qy[r]=ry, r++;
    while (f<r)
    {
        for (int i=0; i<4; i++)
        {
            int vx=qx[f]+wal[i][0], vy=qy[f]+wal[i][1];
            if (can(vx,vy))
            {
                vis[vy][vx]=t;
                qx[r]=vx, qy[r]=vy, r++;
            }
        }
        f++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (t=1; t<=T; t++)
    {
        cin >> mY >> mX;
        for (int y=0; y<mY; y++)
            cin >> G[y];

        int res=0;
        for (int y=0; y<mY; y++)
            for (int x=0; x<mX; x++)
                if (can(x,y))
                    res++, bfs(x,y);
        cout << res << '\n';
    }
}
