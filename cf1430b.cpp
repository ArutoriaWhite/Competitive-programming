#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int t, n, k, a[N];

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) cin >> a[i];
        sort(a+1, a+1+n, [](int i,int j){return i>j;});
        int ans = 0;
        rep(i,1,min(n,k+1)) ans += a[i];
        cout << ans << '\n';
    }
}