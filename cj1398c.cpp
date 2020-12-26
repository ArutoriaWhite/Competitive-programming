#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int a[N];
map<int,int> mp;

signed main()
{
    XinAi
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        mp.clear();
        string s;
        cin >> s;
        for (int i=1; i<=n; i++)
            a[i] = a[i-1] + s[i-1] - '0';
        int res = 0;
        for (int i=0; i<=n; i++)
        {
            res += mp[i - a[i]];
            mp[i - a[i]]++;
        }
        cout << res << '\n';
    }
}