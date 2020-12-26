#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
/*
query max factor in 1~k
*/

signed main()
{
    exploootion
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int ans = 1;
        rep(i,1,sqrt(n)+1)
        {
            if (n%i) continue;
            if (i<=k) ans = max(i, ans);
            if (n/i<=k) ans = max(n/i, ans);
        }
        cout << n/ans << '\n';
    }
}