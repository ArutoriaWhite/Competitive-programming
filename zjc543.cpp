#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10, M =1e9+7;

int dp[N][10], n, res;
string s;
inline void build ()
{
    for (int i=1; i<=9; i++)
        dp[1][i] = 1;
    for (int i=2; i<N; i++)
        for (int j=0; j<=9; j++)
            for (int k=j; k<=9; k++)
                dp[i][j] = (dp[i][j]+dp[i-1][k])%M;
}
inline int jie ()
{
    if (s.size()==1) return 1;
    for (int i=0; i<n-1; i++)
    {
        if (s[i]>s[i+1])
            return 0;
    }
    return 1;
}

signed main()
{
    Eriri
    build();
    while (cin >> s)
    {
        res = 0;
        n = s.size();
        int p = 0;
        for (int i=0; i<n; i++)
        {
            if (s[i]-'0' < p) break;
            for (int j=p; j<s[i]-'0'; j++)
                res = (res+dp[n-i][j])%M;
            p = s[i]-'0';            
        }
        if (jie()) res = (res+1)%M;
        cout << res << '\n';
    }
}