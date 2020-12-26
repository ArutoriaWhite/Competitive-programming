#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N = 210;

int n[5], aww[5][N], ans, dp[N][N][N];
/*
dp[i][j][k] = max(dp[i+1][j+1][k+1], )
*/
signed main()
{
    XinAi
    rep(i, 1, 3) cin >> n[i];
    rep(i, 1, 3) rep(j, 1, n[i]) cin >> aww[i][j];
    rep(i, 1, 3) sort(aww[i]+1, aww[i]+1+n[i]);
    int i[5];
    for (i[1]=n[1]+1; i[1]>0; i[1]--)
    {
        for (i[2]=n[2]+1; i[2]>0; i[2]--)
        {
            for (i[3]=n[3]+1; i[3]>0; i[3]--)
            {
                for (int a=0; a<8; a++) // +1
                {
                    for (int b=0; b<8; b++) // used
                    {
                        int owo=0;
                        for (int tmp=b; tmp; tmp>>=1) owo += tmp&1;
                        if (owo==1 || owo==3) continue;
                        int flag = 0;
                        for (int ta=a,tb=b; ta||tb; ta>>=1,tb>>=1)
                            flag |= !(ta&1) && (tb&1);
                        if (flag) continue;
                        int v[5] = {0, i[1], i[2], i[3]};
                        for (int j=1,ta=a; ta; ta>>=1,j++) v[j] += ta&1;
                        if (owo == 0)
                            dp[i[1]][i[2]][i[3]] = max(dp[i[1]][i[2]][i[3]], dp[v[1]][v[2]][v[3]]);
                        else
                        {
                            int qaq = 1;
                            for (int j=1,tb=b; tb; tb>>=1, j++)
                                if (tb&1) qaq *= aww[j][i[j]];
                            dp[i[1]][i[2]][i[3]] = max(dp[i[1]][i[2]][i[3]], dp[v[1]][v[2]][v[3]] + qaq);
                        }
                    }
                }
                // /de(i[1]), de(i[2]), de(i[3]), de(dp[i[1]][i[2]][i[3]]), dd
                ans = max(ans, dp[i[1]][i[2]][i[3]]);
            }
        }
    }
    cout << ans << '\n';
}