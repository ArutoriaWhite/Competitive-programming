#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
/*
給你 n 個正整數和最大值和最小值，請你決定每個數字的正負，使所有前墜和都在最大和最小區間，並且使整個序列和最大。
如果辦不到輸出 -1

dp[i][j]: 取前 i 個數字，和為 j，辦不辦的到
1. add c[i]
dp[i][j] = dp[i-1][j - c[i]]
2. minus c[i]
dp[i][j] = dp[i-1][j + c[i]]

dp[0][begin_level] = 1
*/
const int N = 60, M = 1010;

int dp[N][M], op, mxlim, c[N], n;

inline int ans ()
{
    for (int i=mxlim; i>=0; i--)
        if (dp[n][i])
            return i;
    return -1;
}

signed main()
{
    cin >> n >> op >> mxlim;
    dp[0][op] = 1;
    rep(i,1,n) cin >> c[i];
    rep(i,1,n)
    {
        rep(j,0,mxlim)
        {
            if (j-c[i] >= 0)
            {
                dp[i][j] |= dp[i-1][j-c[i]];
            }
            if (j+c[i] <= mxlim)
            {
                dp[i][j] |= dp[i-1][j+c[i]];
            }
        }
    }
    cout << ans() << '\n';
}
