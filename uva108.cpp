#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 110;

int w[N][N], n, sum_ver[N][N], ans;

inline int sol (int u, int d)
{
    int res = -1e9;
    for (int i=1,dp=0; i<=n; i++)
        dp = max(0,dp+sum_ver[i-1][d]-sum_ver[i-1][u]), res = max(res,dp);
    return res;
}

int main()
{
    Eriri
    cin >> n;
    for (int y=0; y<n; y++)
        for (int x=0; x<n; x++)
            cin >> w[x][y];
    for (int x=0; x<n; x++)
        for (int y=1; y<=n; y++)
            sum_ver[x][y] = sum_ver[x][y-1]+w[x][y-1];
    for (int i=0; i<n; i++)
        for (int j=i; j<=n; j++)
            ans = max(ans,sol(i,j));
    cout << ans << '\n';
}