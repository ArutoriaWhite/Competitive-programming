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
dp[i][j][k] = 
    enum i..j as l
        enum l..j as r
            dp[i][j][k] += dp[l][r][k-1];

k 級分值，計算每個字串
*/
const int N = 100;
int cnt[N][N], n, k, O;

void calc (int l, int r, int k)
{
    O++;
    if (k==0)
    {
        cnt[l][r]++;
        return;
    }
    for (int i=l; i<=r; i++)
    {
        for (int j=i; j<=r; j++)
        {
            calc(i,j,k-1);
        }
    }
}
signed main()
{
    cin >> n >> k;
    calc(0,n-1,k);
    for (int i=0; i<n; i++)
    {
        for (int l=0,r=i; r<n; l++,r++)
        {
            de(l), de(r), de(cnt[l][r]), dd;
        }
    }
    de(O), dd;
}

