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
const int N = 50;

vector<int> a, lset, rset, lres, rres;
int n, c;

void dfs (int i, int sum, vector<int> &s, vector<int> &res)
{
    if (i >= s.size())
    {
        res.pb(sum);
        return;
    }
    dfs(i+1,sum+s[i],s,res);
    dfs(i+1,sum,s,res);
}

signed main()
{
    cin >> n >> c;
    rep(i,1,n)
    {
        int x; cin >> x;
        if (x > c) break;
        a.pb(x);
    }

    for (int i=0; i<a.size(); i++)
        (i<a.size()/2? lset:rset).pb(a[i]);

    dfs(0,0,lset,lres);
    dfs(0,0,rset,rres);

    sort(rres.begin(), rres.end());

    int ans = 0;
    for (auto x: lres)
    {
        if (x + *rres.begin() > c) continue;
        int y = *(--upper_bound(rres.begin(), rres.end(), c-x));
        ans = max(ans, x+y);
    }
    cout << ans << '\n';
}