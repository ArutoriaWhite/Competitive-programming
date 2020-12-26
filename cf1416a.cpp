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
const int N = 3e5+10;

int t, n;
int a[N], lim[N], ans[N], pre[N];

signed main()
{
    ruru
    cin >> t;
    while (t--)
    {
        memset(lim,0,sizeof(lim));
        memset(ans,0x3f,sizeof(ans));
        memset(pre,0,sizeof(pre));
        cin >> n;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) lim[a[i]] = max(lim[a[i]], i-pre[a[i]]), pre[a[i]]=i;
        rep(i,1,n) lim[i] = max(lim[i], n+1-pre[i]);
        rep(i,1,n) ans[lim[i]] = min(ans[lim[i]], i);
        rep(i,1,n) ans[i] = min(ans[i], ans[i-1]);
        rep(i,1,n) cout << (ans[i]>1e9? -1 : ans[i]) << ' ';
        cout << '\n';
    }
}