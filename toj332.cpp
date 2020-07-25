#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int M = 1e8+7;

ll x=1, y=1, m, n, a;
ll qpow (ll a, ll b)
{
    for (ll rt=1,t[]={1,a}; b>=0; rt=(rt*t[b&1])%M, b>>=1, t[1]=(t[1]*t[1])%M)
        if (!b) return rt;
}

int main()
{
    Eriri
    cin >> m >> n;
    for (int i=0; i<m; i++)
        cin >> a, x = (x*a)%M;
    for (int i=0; i<n; i++)
        cin >> a, y = (y*a)%M;
    cout << (qpow(x,n)*qpow(y,m))%M << '\n';
}