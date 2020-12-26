#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+10;

int ans[N], q[N], n;

inline int query (int l, int r)
{
    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
}

signed main()
{
    cin >> n;
    rep(i,1,n-1) q[i] = query(i,n);
    rep(i,1,n-2) ans[i] = q[i]-q[i+1];
    ans[n] = q[1] - query(1,n-1);
    rep(i,1,n) if(i!=n-1) ans[n-1] += ans[i];
    ans[n-1] = q[1]-ans[n-1];
    cout << "! ";
    rep(i,1,n) cout << ans[i] << ' ';
    cout << endl;
}