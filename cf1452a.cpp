#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
/*
if (i&1) dp[i] = dp[i-1]+1
else dp[i] = max(dp[i-1]+1, dp[i/2]+i/2)
dp[1] = 1
dp[2] = 1
dp[3] = 2
dp[4] = 3
dp[5] = 4
dp[6] = 

如果 x/2 是偶數
如果 x/2 是奇數
*/

signed main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int res=0, st=1;
        while (n>0)
        {
            if (n&1 || (n%4==0&&n>8))
            {
                n--;
                if (st&1) res++;
            }
            else 
            {
                n/=2;
                if(st&1) res += n;
            }
            st++;
        }
        cout << res << '\n';
    }
}