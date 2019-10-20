#include<iostream>
#include<cstring>
using namespace std;
#define maxN 60
#define maxQ 10000
#define DE cout << " ::"
char map[maxN][maxN];
int  G[maxN][maxN]; // -1 vis, 0 cango, 1 blocked
int n, m, rtx, rty;

int q[maxN][2];
int front, rear;
int F[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}};
inline void init()
{
    front=0, rear=0;
    q[rear++][0]=rtx, q[rear][1]=rty;
    map[rtx][rty]='0';
    G[rtx][rty]=-1;
}
void BFS()
{
    init();
    while (rear>front)
    {
        int ux=q[front++][0], uy=q[front][1];
        for( int i=0; i<4; i++)
        {
            int vx=ux+F[i][0], vy=uy+F[i][1];
            if (G[vx][vy]>0)
            {
                map[vx][vy]='X';
                continue;
            }
            if (G[vx][vy]<0)
            {
                continue;
            }
            G[vx][vy]=-1;
            map[vx][vy]='0';
            q[rear++][0]=vx, q[rear][1]=vy;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m)
    {
        if (n==0&&m==0) break;
        for( int x=0; x<maxN; x++)
        {
            for( int y=0; y<maxN; y++)
            {
                G[x][y]=0;
                map[x][y]='?';
            }
        }
        cin >> rtx >> rty;
        for( int y=1; y<=n; y++)
        {
            for( int x=1; x<=m; x++)
            {
                char c;
                cin >> c;
                G[x][y] = (c=='X');
            }
        }
        BFS();

        for( int y=1; y<=n; y++)
        {
            for( int x=1; x<=m; x++)
            {
                cout << map[x][y];
            }
            cout << '\n';
        }
    }


}