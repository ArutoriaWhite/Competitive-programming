#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 2e4+10;

pair<int,int> a[N];
int t, n;
vector<int> dp;

int cmp (pii x, pii y)
{
    if (x.ff != y.ff) return x.ff < y.ff;
    else return x.ss > y.ss;
}
void lis()
{
    dp.clear();
    rep(i,1,n)
    {
        if (dp.empty() || dp.back()<a[i].ss)
        {
            dp.pb(a[i].ss);
            continue;
        }
        *lower_bound(dp.begin(), dp.end(), a[i].ss) = a[i].ss;
    }
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i].ff >> a[i].ss;
        sort(a+1,a+1+n,cmp);
        lis();
        cout << dp.size() << '\n';
    }
}