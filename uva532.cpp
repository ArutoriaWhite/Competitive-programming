#include<iostream>
#include<queue>
using namespace std;
const int N = 35, M = 1e6;

struct ele { int z, y, x, d; };
int MX, MY, MZ, vis[N][N][N], t=0, f, r;
int walk[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };
string G[N][N];
ele q[M];

inline void init()
{
    f=0,r=0,t++;
}

inline void can (ele &rt)
{
    return (0<=e.z&&e.x<MZ && 0<=e.y&&e.y<MY && 0<=e.x&&e.x<MX && vis[e.z][e.y][e.x]<t) ;
}

int bfs ( ele &rt )
{
    q[r++] = rt;
    while (f<r)
    {
        ele &u = q[f++];
        if (G[u.z][u.y][u.x] == 'E') return u.d;
        for (int i=0; i<6; i++)
        {
            ele v {u.z+walk[i][0], u.y+walk[i][1], u.x+walk[i][2], u.d+1};
            if (!can(v)) continue;
            vis[
        }
    }
    return -1;
}

int main()
{
    while (cin >> MZ >> MY >> MX)
    {
        if (MZ==0 && MY==0 && MZ==0) return 0;
        init();

        int rtx, rty, rtz;
        for (int z=0; z<MZ; z++)
        {
            for (int y=0; y<MY; y++)
            {
                cin >> G[z][y];
                for (int x=0; x<MX; x++)
                    if (G[z][y][x] == 'S') rtx=x, rty=y, rtz=z;
            }
        }
        int res = bfs( ele{rtz,rty,rtx} );
        if (res == -1)  cout << "Trapped!\n";
        else cout << "Escaped in " << res << " minute(s).\n"
    }
}