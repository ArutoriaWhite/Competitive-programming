#include <bits/stdc++.h>
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int N = 1010, V = 20010, M = 998244353;

//dp[i][d] = 
// rep j [1,i] 
//  dp[i][d] += dp[j][a[i]-a[j]]

// res = dp[all_i][all_d]
//以 i 為結尾, 公差為 d 的等差數列可能數

int n, a[N], dp[N][V<<1], sf = 20000, res;

int main()
{
    Eriri
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    res = n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            dp[i][a[i]-a[j]+sf] = (dp[i][a[i]-a[j]+sf] + dp[j][a[i]-a[j]+sf] + 1)%M, res = (res+dp[j][a[i]-a[j]+sf] + 1)%M;


    cout << res << '\n';
}