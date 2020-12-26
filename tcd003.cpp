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
const int N = 5e4+10;

int a[N], res;
int n, L;

void sol (int l, int r)
{
    auto sl = upper_bound(a+1,a+1+n,l);
    auto sr = lower_bound(a+1,a+1+n,r);
    if (sr-sl<1) return;

    auto mp = lower_bound(sl,sr,(l+r)>>1);
    if (mp==sr) mp--;
    else if (mp-a>1 && *mp + *(mp-1) >= (l+r))
    {
        mp--;
    }
    res += r-l;
    sol(l,*mp);
    sol(*mp,r);
}

signed main()
{
    cin >> n >> L;
    rep(i,1,n) cin >> a[i];
    sol(0,L);
    cout << res << '\n';
}