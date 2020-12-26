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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 3e4+10;

int a[N], t, n;

int legal()
{
    int ca=a[1], cb=0;
    rep(i,1,n)
    {
        if (ca+cb == a[i]) continue;
        if (ca+cb > a[i]) ca -= ca+cb-a[i];
        else if (ca+cb < a[i]) cb += a[i]-ca-cb;
        if (ca<0 || cb<0)
        {
            return 0;
        }
    }
    return 1;
}

signed main()
{
    cin >> t;
    while (t--)
    { 
        cin >> n;
        rep(i,1,n) cin >> a[i];
        cout << (legal()? "YES":"NO") << '\n';
    }
}