#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int a[N], v[N], sz, n, p[N];
inline void update (int p)
{
    int id = p/sz, l = id*sz, r = min( (id+1)*sz-1, n-1);
    v[id] = 0;
    for (int i=l; i<=r; i++) v[id] += a[i];
}
inline int query (int l, int r)
{
    int res = 0;
    int lid = l/sz, rid = r/sz;
    if (lid == rid)
    {
        for (int i=l; i<=r; i++) res += a[i];
        return res;
    }
    for (int i=lid+1; i<rid; i++) res += v[i];
    int lb = min(n-1, (lid+1)*sz-1);
    int rb = rid*sz;
    for (int i=l; i<=lb; i++) res += a[i];
    for (int i=rb; i<=r; i++) res += a[i];
    return res;
}

signed main()
{
    XinAi;
    int q, l, r;
    cin >> n, sz = sqrt(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i*sz<n; i++) update(i*sz);
    cin >> q;
    for (int i=0; i<q; i++)
    {
        cin >> l >> r, l--, r--;
        if (l > r) swap(l, r);
        cout << query(l, r) << '\n';
    }
}