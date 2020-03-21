#include<iostream>
using namespace std;
const int N = 1e3+10;

int arr[N], dp[N][N];

int main()
{
    int n;
    while (cin >> n)
    {
        int sum=0;
        for (int i=0; i<n; i++)
            cin >> arr[i], sum+=arr[i];
            
        for (int k=1; k<=n; k++)
        {
            for (int i=0,j=k; j<=n; i++,j++)
            {
                bool turn = (n-k+1)&1;
                if (turn)
                    dp[i][j] = max( dp[i+1][j]+arr[i], dp[i][j-1]+arr[j-1]);
                else
                    dp[i][j] = min( dp[i+1][j], dp[i][j-1]);
            }
        }
        cout << dp[0][n] << ' ' << sum-dp[0][n] << '\n';
    }
}