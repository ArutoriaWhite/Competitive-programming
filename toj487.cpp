#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 3010;

int G[N][N], my, mx, rx, ry, tx, ty;
int vis[N][N];
int tow[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<Pii> q;

inline bool can (int x, int y, int vx, int vy)
{
    if (vx<0 || vx>=mx || vy<0 || vy>=my || vis[vx][vy]) return 0;
    int d = G[vx][vy]-G[x][y];
    return -2<=d&&d<=1;
}
inline bool boom (int x, int y)
{
    return abs(x-tx) + abs(y-ty) <= 3;
}
inline bool bfs ()
{
    q.push({rx,ry});
    while (!q.empty())
    {
        int x = q.front().F, y = q.front().S; q.pop();
        if (boom(x,y)) return 1;
        for (int i=0,vx,vy; i<4; i++)
        {
            vx = x+tow[i][0], vy = y+tow[i][1];
            if (can(x,y,vx,vy))
                q.push({vx,vy}), vis[vx][vy] = 1;
        }
    }
    return 0;
}

int main()
{
    Eriri
    cin >> mx >> my;
    for (int x=0; x<mx; x++)
        for (int y=0; y<my; y++)
            cin >> G[x][y];
    cin >> rx >> ry >> tx >> ty;
    rx--, ry--, tx--, ty--;
    if (bfs()) cout << "yes\n";
    else cout << "no\n";
}
/*
5 5 0 0 0 0 0 3 3 3 3 0 3 3 3 3 0 3 3 3 3 3 3 3 3 3 3 1 1 5 5 
3 3 0 2 4 2 4 6 4 6 8 1 1 3 3
3 3 0 2 4 2 4 6 4 6 8 3 3 1 1 
*/