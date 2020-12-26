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
const int N = 1e5+10;

int n, k;
int a[N], pre[N];
set<int> s;

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) a[i] += a[i-1];
    int res = 0;
    s.insert(0);
    rep(i,1,n)
    {
        auto p = s.lower_bound(a[i]-k);
        if (p!=s.end())
        {
            int aj = *p;
            res = max(res, a[i]-aj);
        }
        s.insert(a[i]);
    }
    cout << res << '\n';
}