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

int n, m;
int a[N], pre[N], ans[N], mx;
struct Q { int l, r, id; } q[N];

signed main()
{
    ShinraTensei
    cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
    }
    cin >> m;
    rep(i,1,m)
    {
        int l, r;
        cin >> l >> r;
        if (l > r) swap(l,r);
        q[i] = {l,r,i};
    }

    sort(q+1,q+1+m,[](Q i, Q j){return i.l > j.l;});

    // the latest updated
    int curl = q[1].l+1, curr = q[1].l-1;
    rep(i,1,m)
    {
        while (curr<q[i].r)
        {
            curr++;
            pre[curr] = max(pre[curr-1],a[curr]);
        }
        while (curl>q[i].l)
        {
            curl--;
            mx = max(mx,a[curl]);
        }
        ans[q[i].id] = max(pre[q[i].r],mx);
    }
    rep(i,1,n) cout << ans[i] << '\n';
}