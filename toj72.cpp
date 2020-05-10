#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1000, M = 1e6+10;

int k, p, r, f[N], w[N], dp[M];

int main()
{
    Eriri
    cin >> k >> p;
    for (int i=0,a,b,c; i<k; i++)
    {
        cin >> a >> b >> c;
        for (int j=1; j<=a; a-=j,j<<=1)
            f[r] = j*b, w[r++] = j*c;
        f[r] = a*b, w[r++] = a*c;
    }
    for (int i=0; i<r; i++)
        for (int j=p; j>=w[i]; j--)
            dp[j] = max(dp[j],dp[j-w[i]]+f[i]);
    cout << dp[p] << '\n';
}