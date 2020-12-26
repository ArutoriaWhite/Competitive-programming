#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 100;

map<int,int> mp;
int n, t;

signed main()
{
    XinAi
    cin >> t;
    while (t--)
    {
        mp.clear();
        cin >> n;
        while (n--)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        int ans = 0;
        for (int i=0; i<=100; i++)
        {
            int res = 0;
            for (auto kvp: mp)
            {
                int owo = i - kvp.F;
                res += min(mp[owo], kvp.S);
            }
            ans = max(res, ans);
        }
        cout << ans/2 << '\n';
    }
}
