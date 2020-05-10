#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

int m, n, p;

signed main()
{
    cin >> n >> m >> p;
    m%=p, n%=p;
    cout << ((((n-m+p)%p*m)%p)*n)%p << '\n';
}