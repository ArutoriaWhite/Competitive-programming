#include <bits/stdc++.h>
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int lval[N], rval[N], lrk[N], rrk[N], used[N], a[N], rear;
int n, k, dp[400][400], vis[N];

inline bool cmp1 (int i,int j)
{
    return lval[i] > lval[j];
}
inline bool cmp2 (int i, int j)
{
    return rval[i] > rval[j];
}

signed main()
{
    Eriri
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> lval[i] >> rval[i];
	for (int i=0; i<n; i++)
		lrk[i] = rrk[i] = i;
	sort(lrk,lrk+n,cmp1);
	sort(rrk,rrk+n,cmp2);
	for (int i=0; i<2*k; i++)
	{
		a[rear++] = lrk[i];
		vis[lrk[i]] = 1;
	}
	for (int i=0; i<2*k; i++)
		if (!vis[rrk[i]])
			a[rear++] = rrk[i];
    // dp[p][i][j]
    // in [0,p)
    // l can take i, r can take j
    // max score
    // = max( dp[p-1][i-1][j]+val[a[p-1]], dp[p-1][i][j-1] + val[a[p-1]])
    for (int p=0; p<rear; p++)
    {
        for (int i=k; i>=0; i--)
        {
            for (int j=k; j>=0; j--)
            {
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + lval[a[p]]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + rval[a[p]]);
            }
        }
    }
    cout << dp[k][k] << '\n';
}
/*
7 2
3 5
2 7
4 4
3 1
6 6
2 6
0 1
*/
