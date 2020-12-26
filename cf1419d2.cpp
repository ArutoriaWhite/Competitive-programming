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
const int N = 1e5+10;

int a[N], n, ans[N];

signed main()
{
    SakuraMyWife
    cin >> n;
    rep(i,1,n) cin >> a[i];
    sort(a+1, a+1+n);
    int k = n/2;
    rep(i,1,k) ans[i*2] = a[i];
    rep(i,k+1,n) ans[(i-k)*2-1] = a[i];
    int sum=0;
    rep(i,2,n-1)
        if (ans[i-1]>ans[i]&&ans[i]<ans[i+1])
            sum++;
    cout << sum << '\n';
    rep(i,1,n) cout << ans[i] << ' ';
    cout << '\n';
}