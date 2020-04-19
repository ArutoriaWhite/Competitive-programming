#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 30;

int dp[N][N], mx, my, p, q, tow[9][2] = {{0,0},{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};// dp[i][j] = dp[i+1][j] + dp[i][j+1];

signed main()
{
    yukari;
    cin >> mx >> my >> p >> q;
    dp[mx][my] = 1;
    for (int ty=my; ty>=0; ty--)
    {
        for (int tx=mx; tx>=0; tx--)
        {
            dp[tx][ty] += dp[tx+1][ty] + dp[tx][ty+1];
            for (int i=0; i<9; i++)
                if (tx == p+tow[i][0] && ty == q+tow[i][1])
                    dp[tx][ty] = 0;
        }
    }
    cout << dp[0][0] << '\n';
}