#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 510, MAX = 2147483647;

int a[N], n, t;
long long dp[N];
string s;

inline void init()
{
    n = s.size();
    for (int i=0; i<n; i++)
        a[i] = s[i]-'0';
    memset(dp,-1,sizeof(dp));
}
inline long calc (int l, int r)
{
    long long res = 0;
    for (int i=l; i<r; i++)
    {
        res = res*10 + a[i];
        if (res>MAX) return -1;
    }
    return res;
}
inline bool avai (int l, int r)
{
    return calc(l,r)!=-1 && ((a[l]!=0) || (r-l==1));
}
long long f (int i)
{
    if (i==0) return 0;
    if (dp[i] == -1)
        for (int j=0; j<i; j++)
            if (avai(j,i))
                dp[i] = max( dp[i], f(j)+calc(j,i));
    return dp[i];
}

signed main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> s;
        init();
        cout << f(n) << '\n';
    }
}