#include<iostream>
#include<string.h>
using namespace std;
#define maxN 1000000000
#define M 1000000009
#define DE cout << " ::"

int dp[maxN], L;
int f( int n)
{
    if(dp[n]==0)
    {
        for( int i=1; i<=L; i++)
        {
            if ((n-i)<0) continue;
            dp[n] = (dp[n]+f(n-i))%M;
        }
    }
    return dp[n];
}

int main()
{
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;

    int T;
    cin >> T;
    while (T--)
    {
        cin >> L;
        cout << f(L) << '\n';

}
