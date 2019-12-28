#include<iostream>
using namespace std;
#define res dp[n]
#define pre dp[n-1]
const int N = 1e5+10, M = 1000007;

int dp[N][8] = {1}, n=1;

int f (int q)
{
    while (n<=q)
    {
        res[0] = ((pre[4]+pre[1])%M+pre[7])%M;
        res[4] = (pre[0]+pre[3])%M;
        res[2] = pre[5];
        res[6] = pre[1];
        res[1] = (pre[0]+pre[6])%M;
        res[5] = pre[2];
        res[3] = pre[4];
        res[7] = pre[0];
        n++;
    }
    return dp[q][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, x;
    cin >> T;
    while (T--)
    {
        cin >> x;
        cout << f(x) << '\n';
    }
}