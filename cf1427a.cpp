#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ruru ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int t, n, a[N];

signed main()
{
    ruru
    cin >> t;
    while (t--)
    {
        cin >> n;
        int sum=0;
        rep(i,1,n) cin >> a[i], sum += a[i];
        if (sum == 0) 
        {
            cout << "NO\n";
        }
        else if (sum > 0)
        {
            cout << "YES\n";
            rep(i,1,n)
            {
                if (a[i] > 0) cout << a[i] << ' ';
            }
            rep(i,1,n)
            {
                if (a[i] <= 0) cout << a[i] << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "YES\n";
            rep(i,1,n)
            {
                if (a[i] < 0) cout << a[i] << ' ';
            }
            rep(i,1,n)
            {
                if (a[i] >= 0) cout << a[i] << ' ';
            }
            cout << '\n';
        }
    }
}