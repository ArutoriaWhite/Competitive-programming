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

int cnt[N];

signed main()
{
    XinAi
    int t;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        int mx = 0;
        rep(i, 1, n)
        {
            int a;
            cin >> a;
            cnt[a]++;
            mx = max(mx, cnt[a]);
        }
        int boss = 0;
        rep(i, 1, n) boss += cnt[i] >= mx;
        cout << (n - boss*mx)/(mx-1) + boss - 1 << '\n';
        /*
        (sum - a1)/(a1-1)
        */
    }
}