#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int a[N], n;

signed main()
{
    XinAi
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        int res=0;
        rep(i,1,n)
        {
            if (a[i] > 0) res += a[i];
            else res = max(0LL, res+a[i]);
        }
        cout << res << '\n';
    }
}