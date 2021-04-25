#include <iostream>
using namespace std;
const int N = 5010, M = 1e9+7;

int n;
long long dp[N];

signed main()
{
    cin >> n;
    dp[0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=0,k=i-1; j<i; j++,k--)
            dp[i] = (dp[i]+dp[j]*dp[k]%M)%M;
    cout << dp[n] << '\n';
}