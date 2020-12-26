#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    haaachamachama
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k = sqrt(n), kk=k+1;
        int res = min((n-1)/k+k, (n-1)/kk+kk);
        cout << res-1 << '\n';
    }
}