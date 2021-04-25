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

const int N = 5e5+10;

int n, m, a[N];
int bmx[N], bsz;

inline void build ()
{
    bsz = sqrt(n)+1;
    rep(i,1,n)
    {
        bmx[i/bsz] = max(bmx[i/bsz], a[i]);
    }
}
inline int query (int l, int r)
{
    int lblock = l/bsz;
    int rblock = r/bsz;
    int rbound = (lblock+1)*bsz-1;
    int lbound = rblock*bsz;
    
    int ans = 0;
    if (lblock == rblock)
    {
        for (int i=l; i<=r; i++)
            ans = max(ans, a[i]);
    }
    else
    {
        for (int i=l; i<=rbound; i++)
            ans = max(ans, a[i]);
        for (int i=lbound; i<=r; i++)
            ans = max(ans, a[i]);
        for (int i=lblock+1; i<rblock; i++)
            ans = max(ans, bmx[i]);
    }
    return ans;
}

signed main()
{
    ShinraTensei
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    build();
    cin >> m;
    while (m--)
    {
        int l, r; cin >> l >> r;
        if (l > r) swap(l,r);
        cout << query(l-1,r-1) << '\n';
    }
}
