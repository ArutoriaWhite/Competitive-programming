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

signed main()
{
    XinAi
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n==2 || n==3) cout << -1 << '\n';
        else
        {
            for (int i=n; i>0; i--) if (i&1) cout << i << ' ';
            cout << 4 << ' ' << 2 << ' ';
            for (int i=6; i<=n; i++) if (!(i&1)) cout << i << ' ';
        }
    }
}