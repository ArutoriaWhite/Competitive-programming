#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string s, x, p[210];
int dp[200010], len[210], n, sz;

inline bool check (int i, int j)
{
    for (int a=0,b=i-len[j]; a<len[j]; a++,b++)
        if (s[b]!=p[j][a])
            return 0;
    return 1;
}

int main()
{
    while (cin >> x && x!=".")
        p[sz] = x, len[sz] = p[sz].size(), sz++;
    while (cin >> x)
        s += x;
    n = s.size(), dp[0] = 1;

    for (int i=1; i<=n; i++)
        for (int j=0; j<sz; j++)
            if (i>=len[j])
                dp[i] |= (dp[i-len[j]])&&check(i,j);

    for (int i=n; i>=0; i--)
    {
        if (dp[i])
        {
            cout << i << '\n';
            return 0;
        }
    }
}