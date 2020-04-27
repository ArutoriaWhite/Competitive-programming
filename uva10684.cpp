#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 10010;

int dp, a[N], res, n;

int main()
{
    Eriri
    while (cin >> n && n)
    {
        dp = 0, res = 0;
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=1; i<=n; i++)
            dp = max(0,dp+a[i-1]), res = max(res,dp);
        if (res > 0) cout << "The maximum winning streak is " << res << ".\n";
        else cout << "Losing streak.\n";
    }
}