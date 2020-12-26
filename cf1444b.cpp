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
const int N = 3e5+10, MOD = 998244353;

int n, a[N], fac[N], inv[N];

int qpow (int i, int j)
{
    int res=1;
    for (; j; j>>=1,i=i*i%MOD)
        if (j&1) res = res*i%MOD;
    return res;
}   
int C (int i, int j)
{
    return fac[i]*inv[j]%MOD*inv[i-j]%MOD;
}

signed main()
{
    SakuraMyWife
    fac[0] = 1;
    rep(i,1,N-1) fac[i] = fac[i-1]*i%MOD;
    rep(i,1,N-1) inv[i] = qpow(fac[i],MOD-2);
    cin >> n;
    n *= 2;
    rep(i,1,n) cin >> a[i];
    sort(a+1, a+1+n);
    int res = 0;
    rep(i,1,n) res = (res+(i>n/2? a[i]:-a[i])+MOD)%MOD;
    cout << res*C(n,n/2)%MOD << '\n';
}