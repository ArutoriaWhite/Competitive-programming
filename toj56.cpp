#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef unsigned long long ull;

ull a, b, t;

inline ull f (__int128 n, __int128 m)
{
    if (n>m) swap(n,m);
    while (n != 0)
    {
        t = n;
        n = m%n;
        m = t;
    }
    return m;
}

int main()
{
    Eriri
    while (cin >> a >> b)
    {
        ull h1 = f(a,b);
        ull h2 = f(a+b,(__int128)a/(__int128)h1*(__int128)b);
        cout << h2 << '\n';
    }
}