#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

vector<int> x;
int n, k, T;
int dp[N][3];
/*
dp[i][j] = max(dp[i+1][j], dp[lb(val[i]+k)][j-1])
*/
signed main()
{
    XinAi
    cin >> T;
    while (T--)
    {
        x.clear();
        cin >> n >> k;
        rep(i,0,n) dp[i][0]=dp[i][1]=dp[i][2]=0;
        rep(i,1,n)
        {
            int a;
            cin >> a;
            x.push_back(a);
        }
        rep(i,1,n)
        {
            int a;
            cin >> a;
        }
        sort(x.begin(), x.end());
        for (int i=n-1; i>=0; i--)
        {
            for (int j=1; j<=2; j++)
            {
                int q = upper_bound(x.begin(),x.end(),x[i]+k)-x.begin();
                dp[i][j] = max(dp[i+1][j], dp[q][j-1]+q-i);
            }
        }
        cout << dp[0][2] << '\n';
    }
}