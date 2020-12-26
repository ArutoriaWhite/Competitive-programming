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
const int N = 100;

int a[N], t, n;

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        int k=1, clen=0, res=0;
        while (!a[k]) k++;
        while (k<=n)
        {
            if (a[k] == 1) res += clen, clen=0;
            else clen++;
            k++;
        }
        cout << res << '\n';
    }
}