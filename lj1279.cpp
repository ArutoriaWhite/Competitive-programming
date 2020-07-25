#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2010;

/*
dp[i][j]
min distance in A for [i,n), B for [j,n)
dp[i] = min( k + dp[i][j+1],
             k + dp[i+1][j],
             dis(A[i],B[j]) + dp[i+1][j+1]);
*/
int n, m, k, dp[N][N];
string a, b;

int main()
{
    Eriri
    cin >> a >> b >> k;
    n = a.size(), m = b.size();
    for (int i=n; i>=0; i--)
    {
        for (int j=m; j>=0; j--)
        {
            if (i == n)
                dp[i][j] = k*(m-j);
            else if (j == m)
                dp[i][j] = k*(n-i);
            else
            {
                dp[i][j] = min( k+ dp[i][j+1],
                           min( k+ dp[i+1][j],
                                abs(a[i]-b[j]) + dp[i+1][j+1]));
            }
        }
    }
    cout << dp[0][0] << '\n';
}
/*
cmc
snmn
2
*/