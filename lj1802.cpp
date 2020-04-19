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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1100, X = 1100;

// dp[i][s] = max( dp[i+1][s]+lose[i], dp[i+1][s-u[i]]+win[i])

int dp[N][X], l[N], w[N], u[N], n, x;

signed main()
{
    yukari;
    cin >> n >> x;
    for (int i=1; i<=n; i++)
        cin >> l[i] >> w[i] >> u[i];
    for (int i=n; i>0; i--)
    {
        for (int s=0; s<=x; s++)
        {
            dp[i][s] = dp[i+1][s] + l[i];
            if (s >= u[i])
                dp[i][s] = max(dp[i][s], dp[i+1][s-u[i]] + w[i]);
        }
    }
    cout << dp[1][x]*5 << '\n';
}