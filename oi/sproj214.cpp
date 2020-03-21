#include<iostream>
using namespace std;
const int N = 110;

int G[N][N], n, m;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> G[j][i];
    for (int y=1; y<=n; y++)
    {
        for (int x=1; x<=m; x++)
        {
            cout << G[x-1][y]+G[x+1][y]+G[x][y-1]+G[x][y+1]
                   +G[x+1][y+1]+G[x+1][y-1]+G[x-1][y+1]+G[x-1][y-1];
            if (x+1<=m) cout << ' ';
            else cout << '\n';
        }
    }

}