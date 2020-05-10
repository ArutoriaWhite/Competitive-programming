#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 210, M = 1e6;

int dp[N][N], n, m, res;

int main()
{
    Eriri
    for (int i=0; i<N; i++) dp[1][i] = 1;
    for (int i=2; i<N; i++)
        for (int j=i; j<N; j++)
                dp[i][j] = (dp[i-1][j-1]+(dp[i][j-1]*i)%M)%M;
    while (cin >> n >> m && (n||m))
    {
        res = 0;
        for (int i=1; i<=n; i++)
            res = (res+dp[i][m])%M;
        cout << res << '\n';
    }
}