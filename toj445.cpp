#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC 
#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;

int n, dp[20][(1<<15)], vis[20][(1<<15)];

inline int gen (int l, int r)
{
    int k = 14 - (r-l), u = (1<<15)-1;
    u >>= k;
    u <<= l;
    return u;
}
int f (int len, int g)
{
    if (!vis[len][g])
    {
        vis[len][g] = 1;
        if (g == 0) dp[len][g] = 0;
        else if (len > n)  dp[len][g] = 1e9;
        else
        {
            dp[len][g] = f(len+1, g);
            for (int j=0; j+len<=n; j++)
                dp[len][g] = min(dp[len][g], f(len+1,g^gen(j, j+len-1)) + len);
        }
    }
    return dp[len][g];
}
signed main()
{
    XinAi
    string s;
    cin >> s;
    n = s.size();
    int rt = 0;
    for (int i=n-1; i>=0; i--) rt |= ((s[i]=='1')<<i);
    cout << f(1, rt) << '\n';
}