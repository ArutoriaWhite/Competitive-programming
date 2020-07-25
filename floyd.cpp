#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 100;

int d[N][N], n, m, q;

int main()
{
    Eriri
    cin >> n >> m;
    memset(d,0x3f,sizeof(d));
    for (int i=0,u,v,w; i<m; i++)
    {
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cin >> q;
    for (int i=0,u,v; i<q; i++)
    {
        cin >> u >> v;
        if (d[u][v] == 0x3f3f3f3f) cout << -1 << '\n';
        else cout << d[u][v] << '\n';
    }
}
/*
5 5
1 2 3
2 3 4
1 3 8
4 5 2
3 5 5
5
1 3
2 4
4 5
5 4
2 5
*/