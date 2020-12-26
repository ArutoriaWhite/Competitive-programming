#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int a[N], dif[N], t, n;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        int sum = 0;
        rep(i,1,n-1)
        {
            sum += abs(a[i+1] - a[i]);
        }
        int ans = sum;
        rep(i,1,n)
        {
            int x = sum;
            if (i>1)
            {
                x -= abs(a[i-1] - a[i]);
            }
            if (i<n)
            {
                x -= abs(a[i+1] - a[i]);
            }
            if (1<i && i<n)
            {
                x += abs(a[i-1] - a[i+1]);
            }
            ans = min(ans, x);
        }
        cout << ans << '\n';
    }
}

