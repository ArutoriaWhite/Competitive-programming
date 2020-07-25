#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

string s;
int k, n, a[N], dp[N][2], res;;
// dp[i][j], 在 [0,i) 內, 結尾為 j 的最長交錯長度
// dp[i][j] = max{ dp[i-k][j*0], dp[i0][j*0]};

inline bool comp (int op, int ed, int x)
{
    if (op < 0) return 0;
    for (int i=op; i<ed; i++)
        if (a[i] != x)
            return 0;
    return 1;
}

int main()
{
    Eriri
    cin >> k >> s;
    n = s.size();
    for (int i=0; i<n; i++)
        a[i] = 'a'<=s[i] && s[i]<='z';
    for (int i=1; i<=n; i++)
    {
        if (comp(i-k,i,1)) dp[i][1] = dp[i-k][0]+k;
        if (comp(i-k,i,0)) dp[i][0] = dp[i-k][1]+k;
        res = max( res, dp[i][0]);
        res = max( res, dp[i][1]);
    }
    cout << res << '\n';
}
