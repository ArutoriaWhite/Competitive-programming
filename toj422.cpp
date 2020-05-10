#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

long long dp[N], sum[N], n;
//dp[i] = max{ dp[j]+(sum[j]-sum[i])^2 | i<j<=n }

int main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> sum[i], sum[i] += sum[i-1];
    for (int i=0; i<=n; i++) dp[i] = 1e17;
    dp[n] = 0;
    for (int i=n; i>=0; i--)
        for (int j=i+1; j<=n; j++)
            dp[i] = min( dp[i], dp[j]+(sum[j]-sum[i])*(sum[j]-sum[i]) );
    cout << dp[0] << '\n';
}