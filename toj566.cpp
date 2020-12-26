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
const int N = 1e6+10;

int a[N];

signed main()
{
    haaachamachama
    int n;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    int mx=0, mxans=0;
    rep(i,1,n)
    {
        if (a[i] < mx)
            mxans = max(mxans, a[i]);
    }
    cout << max(0LL, mxans) << '\n';
}