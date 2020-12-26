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

int a[N], n, p[N];
map<int,int> cnt;

signed main()
{
    haaachamachama
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) p[i] = p[i-1]+a[i]; 
    cnt[0]++;
    int res=0;
    rep(i,1,n)
    {
        if (cnt[p[i]] > 0)
        {
            res++;
            cnt.clear();
            cnt[p[i-1]]++;
        }
        cnt[p[i]]++;
    }
    cout << res << '\n';
}