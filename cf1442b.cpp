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
const int N = 2e5+10;

int t, n, k, a[N], id[N], b[N], disa[N];

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) cin >> a[i], id[a[i]] = i;
        rep(i,1,k) cin >> b[i], b[i]=id[b[i]], disa[b[i]] = 1;
        int res=1;
        rep(i,1,k)
        {
            int cnt=0;
            if (b[i]>1 && !disa[b[i]-1]) cnt++;
            if (b[i]<n && !disa[b[i]+1]) cnt++;
            disa[b[i]] = 0;
            //de(i), de(cnt), dd;
            res = (res*cnt)%998244353;
        }
        cout << res << '\n';
    }
}