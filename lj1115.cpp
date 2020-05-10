#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

long long dp, n, res = -1e18;

signed main()
{
    cin >> n;
    for (int i=1, a; i<=n; i++)
    {
        cin >> a;
        dp = max(a, dp+a);
        res = max(res, dp);
    }
    cout << res << '\n';
}