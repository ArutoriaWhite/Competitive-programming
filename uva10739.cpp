#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

int dp[N][N], t, n, res;
string s;
/*
if (s[i-1] == s[j]) dp[i][j] = dp[i-1] + dp[j+1] + 1
else dp[i][j] = max(dp[i-1][j], dp[i][j+1])
*/

void print_dp ()
{
    for (int i=0; i<=n; i++)
    {
        de(i), de(dp[i][i]), dend;
    }
}

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        res = 1e9;

        cin >> s, n = s.size();
        for (int i=1; i<=n; i++)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (s[i-1] == s[j])
                    dp[i][j] = dp[i-1][j+1] + 1;
                else
                    dp[i][j] = max( dp[i-1][j], dp[i][j+1]);
            }
        }
        for (int i=1; i<n; i++)
        {
            if (max(i,n-i) - dp[i][i] < res)
            {
                res = max(i,n-i) - dp[i][i] +  ;
                de(i), de(dp[i][i]), de(res), dend;
            }
        }
        cout << res << '\n';
    }
}