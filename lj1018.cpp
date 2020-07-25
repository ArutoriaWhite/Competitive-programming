#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n, m;
string s;
struct big
{
    int n, num[50];
    void operator = (string &s)
    {
        
    }
    big operator * (big &x)
    {

    }
    big operator + (big &x)
    {

    }
} dp[50][10];
inline 

int main()
{
    cin >> n >> m;
    for (int i=0; i<=n; i++)
        dp[i][0] = s.substr(0,i);
    for (int i=0; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            dp[i][j] = "0";
            for (int k=j; k<n; k++)
            {
                big x = s.sub(k,n-k);
                dp[i][j] = _max(dp[i][k]*x, dp[i][j]);
            }
        }
    }
}