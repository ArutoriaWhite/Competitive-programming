#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
const int N = 2e5+10;

int n, k;
LL dp[N], sum[N];

LL f (int i)
{
    if (dp[i] == -1)
    {
        if (n-i < k) dp[i] = 0;
        else dp[i] = max(f(i+k+1)+sum[i+k]-sum[i], f(i+1));
    }
    return dp[i];
}

int main()
{
    Eriri
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> sum[i], sum[i] += sum[i-1];
    cout << f(0) << '\n';
}