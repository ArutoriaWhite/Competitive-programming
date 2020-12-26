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
const int N = 2e5+10;

int tot, a[N], n, odp[N], edp[N], t;

signed main()
{
    haaachamachama
    cin >> t;
    while (t--)
    {
        memset(odp,0,sizeof(odp));
        memset(edp,0,sizeof(edp));
        tot=0;

        cin >> n;
        rep(i,1,n) cin >> a[i], tot+=a[i]*(i&1);
        rep(i,1,n) if(i&1) a[i]*=-1;

        int mx=0;
        odp[1]=a[1];
        rep(i,2,n)
        {
            odp[i] = max(edp[i-1],0LL)+a[i];
            edp[i] = max(odp[i-1]+a[i],0LL);
            mx = max(edp[i], mx);
        }
        //rep(i,1,n) de(i), de(a[i]), de(odp[i]), de(edp[i]), dd;
        cout << tot+mx << '\n';
    }
}