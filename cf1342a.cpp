#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

int x, y, a, b, t;

signed  main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> a >> b;
        b = min(b,a*2);
        cout << (min(x,y)*b + abs(x-y)*a) << '\n';
    }
}