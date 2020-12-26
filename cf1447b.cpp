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

int t, n, m;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        int sum=0, x;
        vector<int> v;
        cin >> n >> m;
        rep(i,1,n) rep(j,1,m) cin >> x, v.pb(x), sum+=x;
        sort(v.begin(), v.end());
        int res = sum;
        for (int i=0; i<SZ(v); i++)
        {
            sum -= v[i]*2;
           if (i&1) res = max(res, sum);
        }
        cout << res << '\n';
    }
}