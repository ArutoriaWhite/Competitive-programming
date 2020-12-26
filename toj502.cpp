#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 300;

int G[N][N];

signed main()
{
    XinAi
    int n, t, s;
    cin >> n >> t >> s;
    for (int i=0,x,y; i<t; i++) cin >> x >> y, G[x][y] = 1;
    int nx=0, ny=0;
    if (G[0][0])
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i=0; i<s; i++)
    {
        char mv;
        cin >> mv;
        if (mv == 'W') nx--;
        if (mv == 'E') nx++;
        if (mv == 'S') ny--;
        if (mv == 'N') ny++;
        if (G[nx][ny])
        {
            cout << i+1 << '\n';
            return 0;
        }
    }
    cout << "(^_^)\n";
}
/*
4
1 3
1 1
E
E
N

4
3 4
1 1
1 2
2 1
N
N
E
S
*/