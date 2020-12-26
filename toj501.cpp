#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int a[N], ans, pr, dp, n;

signed main()
{
    XinAi
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i], a[i+n] = a[i];
    for (int i=1; i<=2*n; i++)
    {
        dp = min(min(pr+1, a[i]), n);
        ans = max(ans, dp);
        pr = dp;
    }
    cout << ans << '\n';
}