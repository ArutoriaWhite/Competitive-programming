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

int n, x;

signed main()
{
    haaachamachama
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int res=1;
        if (n>2)
        {
            res++, n-=2;
            while (n>x) res++, n-=x;
        }
        cout << res << '\n';
    }
}