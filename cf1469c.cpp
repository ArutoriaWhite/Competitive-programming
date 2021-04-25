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
giving h[1..n], d, can you construct an array a such that:
abs(a[i] - a[i-1]) < d
a[1] = h[1]
a[n] = h[n]
h[i]-1 < a[i] < h[i]+d

dp[i][x]: can set a[i] to x be done?
dp[i][x] = dp[i+1][x-d+1] || .. || dp[i+1][x+d-1]

constantly maintance a u, d that dp[i][u]..dp[i][d] == 1

int u=h[1], d = h[1]
rep (i,2,n-1)
    u = min(u+k-1, h[i]+d-1)
    d = max(d-k+1, h[i])
if (d <= h[n] && h[n]<=u) answer ans;
*/
const int N = 2e5+10;
int t, n, k, h[N];

int check ()
{
    int u = h[1], d = h[1];
    rep (i,2,n)
    {
        u = min(u+k-1, h[i]+k-1);
        d = max(d-k+1, h[i]);
        if (u < d) return 0;
    }
    return (d<=h[n] && h[n]<=u);
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) cin >> h[i];
        cout << (check()? "YES":"NO") << '\n';
    }
}