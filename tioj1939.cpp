#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 110;

int dp[N][2][2];

int main()
{
    dp[1][1][1] = dp[2][1][0] = dp[2][0][1] = 1;
    dp[2][1][1] = 2;
    for (int i=3; i<N; i++)
    {
        for (int j=2,k=i-1; j<i; j++,k--)
        {
            dp[i][1][0] += dp[j][1][1]*dp[k][1][0] + dp[j][1][0]*dp[k][0][0];
            dp[i][0][1] += dp[j][0][1]*dp[k][1][0] + dp[j][0][0]*dp
        }

    }
}