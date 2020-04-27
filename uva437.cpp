#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 200;

int dp[N], x[N], y[N], z[N], r, res, n, t;

inline void add (int a, int b, int c)
{
    x[r] = a, y[r] = b, z[r] = c, r++;
}
inline int f (int i)
{
    if (dp[i]==-1)
    {
        dp[i] = z[i];
        for (int j=0; j<r; j++)
            if (x[j]<x[i] && y[j]<y[i])
                dp[i] = max(dp[i],f(j)+z[i]);        
    }
    return dp[i];
}
/*
gen 6*n block
dp[i] -i the last area
*/

int main()
{
    Eriri
    while (cin >> n && n)
    {
        memset(dp,-1,sizeof(dp));
        res = -1e9, r=0, t++;
        for (int i=0,a,b,c; i<n; i++)
        {
            cin >> a >> b >> c;
            add(a,b,c), add(a,c,b), add(b,a,c);
            add(b,c,a), add(c,a,b), add(c,b,a);
        }
        for (int i=0; i<r; i++)
            res = max( res, f(i));
        cout << "Case " << t << ": maximum height = " << res << "\n";
    }
}

