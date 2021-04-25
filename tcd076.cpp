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
const int P = 100, N = 300;

int fac[N], invfac[N], n;

int qpow (int i, int j)
{
    int res=1;
    for (; j; i=i*i%P,j>>=1)
        if (j&1) res = (res*i)%P;
    return res;
}
void build()
{
    fac[1] = 1;
    rep(i,2,N-1) fac[i] = fac[i-1]*i%P;
    rep(i,1,N-1) invfac[i] = qpow(fac[i],P-2);
}
int C (int i, int j)
{
    return fac[i] * invfac[j] % P * invfac[i-j] % P;
}
int catalan (int i)
{
    return (C(2*i,i) - C(2*i,i-1) + P)%P;
}

signed main()
{
    build();
    cin >> n;
    cout << catalan(n) << '\n';
}