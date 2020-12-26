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
const int N = 1e5+10;

int a[N], x, n, t;

signed main()
{
    haaachamachama
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        rep(i,1,n) cin >> a[i];
        sort(a+1, a+1+n);

        int sz=0, res=0;
        for (int i=n; i>0; i--)
        {
            sz++;
            if (a[i]*sz >= x)
            {
                sz=0;
                res++;
            }
        }
        cout << res << '\n';
    }
}