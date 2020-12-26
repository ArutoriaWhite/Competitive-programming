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

int t, n;

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n;
        int x = -1;
        rep(i,2,sqrt(n)+1)
        {
            if (n%i == 0)
            {
                x = i;
                break;
            }
        }
        if (x==-1)
        {
            cout << 1 << ' ' << n-1 << '\n';
        }
        else
        {
            cout << n/x << ' ' << n-(n/x) << '\n';
        }
    }
}