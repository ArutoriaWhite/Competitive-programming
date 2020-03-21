#include <iostream>
#include <cstring>
#define DE cout << " ::"
using namespace std;
const int N = 1e3+10, M = 1e6;

int arr[N][N], n, m;
int qx[M], qy[M], f, r;
int forw[][2] = { {1,1}, {1,0}, {1,-1}, {0,1}, {0,-1}, {-1,1}, {-1,0}, {-1,-1} };

inline bool can (int x, int y)
{
	return (0<=x&&x<n)&&(0<=y&&y<m);	
}

inline void bfs (int rx, int ry)
{
    f=r=0, qx[r] = rx, qy[r]=ry, r++;
    arr[rx][ry] = 0;
    while (f<r)
    {
        int ux = qx[f], uy = qy[f++];
        for (int i=0,vx,vy; i<8; i++)
        {
            vx = ux+forw[i][0], vy = uy+forw[i][1]; 
            if ((!can(vx,vy)) || arr[vx][vy]==0) continue;
            arr[vx][vy] = 0;
            qx[r] = vx, qy[r] = vy, r++;
        }
    }
}

int main()
{
    //ios::sync_with_stdio(0), cin.tie(0);
    while (cin >> m >> n && m!=0 || n!=0)
    {
        memset(arr,0,sizeof(arr));
        string s;
        for (int y=0; y<m; y++)
        {
            cin >> s;
            for (int x=0; x<n; x++)
                arr[x][y] = (s[x]=='1');
        }

        int res = 0;
        for (int x=0; x<n; x++)
            for (int y=0; y<m; y++)
                if (arr[x][y]!=0)
                    bfs(x,y), res++;
        cout << res << '\n';
    }
}
/*
6 8
11100000
11110000
11110011
11100111
11000011
10000011
0 0 

*/
