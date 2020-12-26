#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 5e4+10;

int n, a[N], t;

signed main()
{
    XinAi
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        if (a[1] + a[2] <= a[n])
        {
            cout << 1 << ' ' << 2 << ' ' << n << '\n';
        }
        else 
            cout << -1 << '\n';
    }
}