#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N=3e6+10, M=1e9+7;

int rev[N], fac[N];
inline int qpow (int i, int j)
{
    int res=1;
    for (; j; j>>=1,i=i*i%M)
        if (j&1) res = res*i%M;
    return res;
}
void build ()
{
    fac[0]=1;
    for (int i=1; i<N; i++)
    {
        fac[i] = fac[i-1]*i%M;
        rev[i] = qpow(fac[i],M-2);
    }
}
int C (int i, int j)
{   
    return fac[i]*rev[j]%M*rev[i-j]%M;
}

signed main()
{
    exploootion
    build();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n/=2;
        cout << (C(2*n,n) - C(2*n,n-1)+M)%M << '\n';
    }
}