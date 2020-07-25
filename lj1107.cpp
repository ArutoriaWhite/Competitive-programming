#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
const int N = 2010;

int n, h, d;
int dp[N][N], a[N][N], mx[N];
/*
dp[i][j]: on the ith tree, height is j:
dp[i][j] = max(dp[k][j-2], dp[i][j-1]+1)
*/ 

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> h >> d;
    for (int i=1,x,y; i<=n; i++)
    {
        cin >> x;
        for (int j=1; j<=x; j++)
        {
            cin >> y;
            a[i][y]++;
        }
    }
    for (int j=1; j<=h; j++)
    {
        for (int i=1; i<=n; i++)
        {
            dp[i][j] = a[i][j] + max(dp[i][j-1], mx[j-d]);
            mx[j] = max(mx[j], dp[i][j]);
        }
    }
    cout << mx[h] << '\n';
}