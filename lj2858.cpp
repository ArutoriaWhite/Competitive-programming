#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 3000;

// dp[i][j] = max( dp[i+1][j]+a[i]*(n-(j-i)), dp[i][j-1]+a[j]*(n-(j-i)) )
// dp[i][i] = 0
int dp[N][N], a[N], n;

int main()
{
    MegumiMyWife;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int len=1; len<=n; len++)
    {
        for (int i=0,j=len; j<=n; i++,j++)
        {
            dp[i][j] = max( dp[i+1][j]+a[i]*(n-len+1), dp[i][j-1]+a[j-1]*(n-len+1) );
        }
    }
    cout << dp[0][n] << '\n';
}
