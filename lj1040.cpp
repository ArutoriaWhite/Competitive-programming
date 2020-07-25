#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 40;

long long dp[N][N], w[N];
int rt[N][N], vis[N][N], n;

void f (int l, int r)
{
    if (vis[l][r]) return;
    vis[l][r] = 1;

    if (r-l==1)
        rt[l][r] = l, dp[l][r] = w[l];
    else if (r-l==0)
        dp[l][r] = 1;
    else
    {
        for (int u=l; u<=r; u++)
        {
            f(l,u), f(u+1,r);
            if (dp[l][u]*dp[u+1][r] + w[u] > dp[l][r])
                rt[l][r] = u, dp[l][r] = dp[l][u]*dp[u+1][r] + w[u];
        }        
    }
}
void print (int l, int r)
{
    if (r-l<1) return;
    cout << rt[l][r]+1 << ' ';
    print(l,rt[l][r]), print(rt[l][r]+1,r);
}

int main()
{
    Eriri
    cin >> n;
    for (int i=0; i<n; i++) cin >> w[i];
    f(0,n);
    cout << dp[0][n] << '\n';
    print(0,n), cout << '\n';
}