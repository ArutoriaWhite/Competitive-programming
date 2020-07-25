#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

long long a, b, c;

inline long long qpow ()
{
    for (long long x[]={1,a},r=1; b>=0; r=(r*x[b&1])%c, x[1] = x[1]*x[1]%c, b>>=1)
        if (!b) return r;
}

int main()
{
    cin >> a >> b >> c;
    cout << qpow() << '\n';
}