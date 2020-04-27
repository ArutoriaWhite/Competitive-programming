#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int t, n, k, dp[10010][110], a[10010];

inline int deal (int x)
{
    if (x>=0) return x%k;
    else
    {
        return (k*(abs(x)/k+1) + x)%k;
    }
}

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> n >> k;
        for (int i=0; i<n; i++) cin >> a[i];
        dp[0][0] = 1;
        for (int i=0; i<n; i++)
        {
            for (int x=0; x<k; x++)
            {
                if (dp[i][x])
                {
                    dp[i+1][deal(x+a[i])] = 1;
                    dp[i+1][deal(x-a[i])] = 1;
                }
            }
        }
        if (dp[n][0]) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
}