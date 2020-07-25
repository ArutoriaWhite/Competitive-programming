#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define rep(i,j,k) for (int i=j; i<=k; i++)
using namespace std;
typedef pair<int,int> Pii;
const int N = 55;

int dp[N][N][N][N], a[N][N], mx, my;

int main()
{
    Eriri
    cin >> my >> mx;
    rep(y,1,my)
        rep(x,1,mx)
            cin >> a[x][y];
    dp[1][1][1][1] = 0;
    rep(i,1,mx)
        rep(j,1,my)
            rep(k,1,mx)
                rep(l,1,my)
                    if (i+j == k+l && (i!=k||j!=l))
                        if (i!=1 || j!=1 || k!=1 || l!=1)
                            dp[i][j][k][l] = max( dp[i-1][j][k-1][l],
                                                max( dp[i-1][j][k][l-1],
                                                max( dp[i][j-1][k-1][l],
                                                dp[i][j-1][k][l-1]))) + a[i][j] + a[k][l];
    cout << dp[mx-1][my][mx][my-1] << '\n';
}