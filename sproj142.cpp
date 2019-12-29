#include<iostream>
using namespace std;
const int N=1e5+10;

int dp[N], w[N], k;
inline int f (int n)
{
    dp[0] = w[0];
    for (int i=1; i<k; i++)
        dp[i] = max(dp[i-1],w[i]);
    for (int i=k; i<n; i++)
        dp[i] = max( dp[i-k]+w[i], dp[i-1] );
    return dp[n-1];
}

int main()
{
    int T, x;
    cin >> T;
    while (T--)
    {
        cin >> x >> k;
        for (int i=0; i<x; i++)
            cin >> w[i];
        cout << f(x) << '\n';
    }
}