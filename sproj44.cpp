#include<iostream>
using namespace std;
const int N=110, M=1e6;
#define DE cout << " ::"

string G[N];
int qx[M], qy[M], qd[M], f, r, vis[N][N], t=0;
int walk[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

inline void init()
{
    f=0, r=0, t++;
}
inline int bfs (int rtx, int rty)
{
    qx[r]=rtx, qy[r]=rty, qd[r]=0, r++;
    while (f<r)
    {
        int ux=qx[f], uy=qy[f], d=qd[f]; f++;
        if (G[uy][ux] == '@')
            return d;
        for (int i=0; i<4; i++)
        {
            int vx=ux+walk[i][0], vy=uy+walk[i][1];
            if (G[vy][vx] == '#' || vis[vy][vx]>=t) continue;
            vis[vy][vx] = t;
            qx[r]=vx, qy[r]=vy, qd[r]=d+1; r++;
        }
    }
    return -1;
}

int main()
{
    int n, rtx, rty;
    while (cin >> n)
    {
        if (n==0) return 0;
        init();
        for (int y=0; y<n; y++)
        {
            cin >> G[y];
            for (int x=0; x<G[y].size(); x++)
            {
                if (G[y][x] == 'K')
                {
                    rtx=x, rty=y;
                    break;
                }
            }
        }

        int res = bfs(rtx,rty);
        if (res == -1) cout << "= =\"\n";
        else cout << res << '\n';
    }
}