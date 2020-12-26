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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10, M=99999997;

int tr[N<<1], a[N], b[N], ta[N], tb[N], p[N], n;
int query (int l, int r)
{
    l--;
    int res=0;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if (l&1) res += tr[l++];
        if (r&1) res += tr[--r];
    }
    return res;
}
void add (int p)
{
    p--;
    for (tr[p+=n]+=1; p>1; p>>=1)
        tr[p>>1] = tr[p]+tr[p^1];
}
signed main()
{
    SakuraMyWife
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    rep(i,1,n) ta[i]=a[i], tb[i]=b[i];
    sort(ta+1,ta+1+n), sort(tb+1,tb+1+n);
    rep(i,1,n) a[i]=lower_bound(ta+1,ta+1+n,a[i])-ta;
    rep(i,1,n) b[i]=lower_bound(tb+1,tb+1+n,b[i])-tb;
    rep(i,1,n) p[a[i]] = i;
    int res=0;
    rep(i,1,n) res=(query(p[b[i]],n)+res)%M, add(p[b[i]]);
    cout << res << '\n';
}
/*
按照 a 的順序遍歷 b, 然後計算逆序數對
把 b 轉化成 順序
*/