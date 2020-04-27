#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
typedef const vector<int> &Cvi;
const int N = 1e5+10;

vector<int> a, b, c;
int res;
int na, nb, nc, t;

void sol (Cvi x, Cvi y, Cvi z)
{
    for (auto p: y)
    {
        if (p < x.front() || p > z.back()) continue;
        int s = *(prev(upper_bound(x.begin(),x.end(),p)));
        int t = *(lower_bound(z.begin(),z.end(),p));
        res = min(res, (p-s)*(p-s) + (s-t)*(s-t) + (p-t)*(p-t) );
    }
}

signed main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        res = 9e18;
        cin >> na >> nb >> nc;
        a.resize(na), b.resize(nb), c.resize(nc);
        for (int i=0; i<na; i++) cin >> a[i];
        for (int i=0; i<nb; i++) cin >> b[i];
        for (int i=0; i<nc; i++) cin >> c[i];
        sort(a.begin(),a.end()), sort(b.begin(),b.end()), sort(c.begin(),c.end());
        sol(a,b,c), sol(a,c,b);
        sol(b,a,c), sol(b,c,a);
        sol(c,a,b), sol(c,b,a);
        cout << res << '\n';
    }
}