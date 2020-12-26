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
const int N = 5e5+10;

int n, k;
int a[N], dif[N], lk[N];
vector<int> dp;

int inrange (int i)
{
    int upb = upper_bound(lk+1,lk+1+k,i)-lk;
    if (a[i]>a[lk[upb]]) return 0;
    if (upb>1 && a[i]<a[lk[upb-1]]) return 0;
    return 1;
}

signed main()
{
    SakuraMyWife
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,k) cin >> lk[i];
    a[++n] = 2e18, lk[++k] = n;
    rep(i,1,n) a[i] -= i;
    sort(lk+1, lk+1+k);

    rep(i,2,k)
    {
        if (a[lk[i-1]] > a[lk[i]])
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    //rep(i,1,n) de(i), de(a[i]), dd;

    vector<int> dp;
    int ans=0, len=0;
    rep(i,1,n)
    {
        if (*lower_bound(lk+1,lk+1+k,i) == i)
        {
            //de(i), de(len), de(dp.size()), dd;
            ans += len - dp.size();
            len = 0;
            dp.clear();
            continue;
        }
        len++;
        if (inrange(i))
        {
            if (dp.empty()||a[i]>=dp.back()) dp.pb(a[i]);
            else *upper_bound(dp.begin(),dp.end(),a[i]) = a[i];
        }
    }
    cout << ans << '\n';
}
/*
rep(i,1,n)
    if (is locked)
        ans += tot_len - dp.len
    else if (in_range)
        *upper_bound(all(dp), a[i]) = a[i]
*/