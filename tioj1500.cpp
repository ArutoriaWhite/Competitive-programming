#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 110, V = 1010;

int dp[V], w[N], a[N], n, t;

int main()
{
    MegumiMyWife;
    cin >> t >> n;
    for (int i=0; i<n; i++)
        cin >> w[i] >> a[i];
    for (int i=0; i<n; i++)
        for (int j=t; j>=0; j--)
            if (j >= w[i])
                dp[j] = max(dp[j],dp[j-w[i]]+a[i]);
    cout << dp[t] << '\n';
}