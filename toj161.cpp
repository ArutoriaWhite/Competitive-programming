#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> pii;
const int N = 1e7+10;

int f[N], n, t, m;

signed main()
{
    XinAi
    cin >> t;
    while (t--)
    {
        cin >> f[0] >> f[1] >> m >> n;
        for (int i=2; i<=n; i++)
            f[i] = ((f[i/2]+f[i/3]+f[i/4])*f[i/5])%m;
        cout << f[n] << '\n';
    }
}