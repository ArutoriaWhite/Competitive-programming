#include<iostream>
#include<cstring>
using namespace std;
#define maxN 60
#define maxQ 10000
#define DE cout << " ::"

char map[maxN][maxN];
int  G[maxN][maxN]; // -1 vis, 0 cango, 1 blocked
int n, m, rtx, rty, cnt;

int F[4][2] = { {0,-1}, {1,0}, {0,1}, {-1,0}};
inline void Gen()
{
    int ux=rtx, uy=rty;
    cnt=0;
    map[ux][uy]='0';
    G[ux][uy]=-1;

    bool flag=1;
    while (flag)
    {
        flag=0;
        int nx, ny;
        for( int i=0; i<4; i++)
        {
            int vx=ux+F[i][0], vy=uy+F[i][1];

            if (G[vx][vy]==0)
            {
                map[vx][vy]='0';
                if (!flag)
                {
                    G[vx][vy]=-1;
                    nx=vx,ny=vy;
                    flag=1;
                    cnt++;
                }
            }
            else if (G[vx][vy]>0)
            {
                map[vx][vy]='X';
            }
        }
        ux=nx, uy=ny;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {
        if (n==0&&m==0) break;
        cout << '\n';
        for( int x=0; x<maxN; x++)
        {
            for( int y=0; y<maxN; y++)
            {
                G[x][y]=-1;
                map[x][y]='?';
            }
        }
        cin >> rty >> rtx;
        for( int y=1; y<=n; y++)
        {
            for( int x=1; x<=m; x++)
            {
                char c;
                cin >> c;
                G[x][y] = (c=='X');
            }
        }

        Gen();
    
        for( int y=1; y<=n; y++)
        {
            cout << '|';
            for( int i=0; i<m; i++)
                cout << "---|";
            cout << "\n|";

            for( int x=1; x<=m; x++)
                cout << ' ' << map[x][y] << " |";
            cout << "\n";
        }
        cout << "|";
        for( int i=0; i<m; i++)
            cout << "---|";
        cout << "\n\n";
        cout << "NUMBER OF MOVEMENTS: " << cnt << "\n";
    }
}