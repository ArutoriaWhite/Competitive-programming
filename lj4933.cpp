#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e3+10, M = 2e4+10, P = 998244353;

int dp[N][M*2+10], ans, a[N], n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            dp[i][a[i]-a[j]+M] = 1;
            ans = (ans + dp[i][a[i]-a[j]+M])%P;
        }        
    }
    cout << ans << '\n';
}