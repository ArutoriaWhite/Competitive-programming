#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

long long dp[N][N], primes[N], sz, notp[N], n;

inline void build()
{
    for (int i=2; i<N; i++)
    {
        if (!notp[i]) primes[sz++] = i;
        for (int j=0; j<sz&&primes[j]*i<N; j++)
        {
            notp[primes[j]*i] = 1;
            if (!i%primes[j]) break;
        }
    }
}

inline int f (int i, int s)
{
    if (s==n) return 1;
    if (i>=sz || primes[i]>n) return 0;
    if (dp[i][s] == -1)
    {
        dp[i][s] = 0;
        for (int k=0; s+k<=n; k+=primes[i])
            dp[i][s] += f(i+1,s+k);
    }
    return dp[i][s];
}

signed main()
{
    MegumiMyWife;
    memset(dp,-1,sizeof(dp));
    build();
    cin >> n;
    cout << f(0,0) << '\n';
}