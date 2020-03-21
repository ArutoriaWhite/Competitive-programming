#include<iostream>
using namespace std;
const int N=1e5+10;

int dp[N], w[N];
inline int f (int n)
{
    dp[0] = w[0], dp[1] = max(w[0],w[1]);
    for (int i=2; i<n; i++)
        dp[i] = max( dp[i-2]+w[i], dp[i-1] );
    return dp[n-1];
}

int main()
{
    int T, x;
    cin >> T;
    while (T--)
    {
        cin >> x;
        for (int i=0; i<x; i++)
            cin >> w[i];
        cout << f(x) << '\n';
    }
}