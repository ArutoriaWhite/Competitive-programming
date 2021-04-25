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

int n[5], sum[5], all;
set<int> s[5];
multiset<int> xxx;

signed main()
{
    cin >> n[1] >> n[2] >> n[3];
    rep(i,1,3)
        rep(j,1,n[i])
        {
            int a; cin >> a;
            s[i].insert(a);
            sum[i] += a;
            all += a;
        }
    int ans = 0;
    rep(i,1,3) ans = max(ans, all-2*sum[i]);
    rep(i,1,3) xxx.insert(*s[i].begin());
    ans = max(ans, all - *xxx.begin()*2 - *next(xxx.begin())*2);
    cout << ans << '\n';
}