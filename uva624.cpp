#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 25, M = 5e6;

int dp[N][M], a[N], m, n, nex[N][M], used[N][M], t;

int f (int i, int k)
{
    if (i==n) return 0;
    if (used[i][k] < t)
    {
        used[i][k] = t;
        dp[i][k] = f(i+1,k), nex[i][k] = k;
        if (k >= a[i] && f(i+1,k-a[i])+a[i]>dp[i][k])
            dp[i][k] = f(i+1,k-a[i])+a[i], nex[i][k] = k-a[i];
    }
    return dp[i][k];
}

int main()
{
    Eriri
    while (cin >> m >> n)
    {
        t++;
        for (int i=0; i<n; i++)
            cin >> a[i];
        int res = f(0,m);
        for (int i=0,k=m; i<n; k=nex[i][k],i++)
            if (nex[i][k]!=k) cout << a[i] << ' ';
        cout << "sum:" << res << '\n';
    }
}