#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int P = 24851, N = 24860;

ll fac[N], inv[N], n, m;

inline ll qpow (ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b&1) res = (res*a)%P;
        a = (a*a)%P;
        b>>=1;
    }
    return res;
}
inline ll lucas (ll a, ll b)
{
    if (b == 0) return 1;
    return (lucas(a/P,b/P) * ( (fac[a%P]*inv[b%P])%P * inv[((a%P)-(b%P)+P)%P] )%P)%P;
}

int main()
{
    fac[1] = 1;
    for (int i=2; i<=P; i++)
        fac[i] = (fac[i-1]*i)%P;
    for (int i=1; i<=P; i++)
        inv[i] = qpow(fac[i],P-2);
    cin >> n >> m;
    cout << lucas(n-1,m-1) << '\n';
}


