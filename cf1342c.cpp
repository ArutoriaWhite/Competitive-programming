#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

int t, a, b, q, l, r, i, j, x, y;

inline int calc (int x, int y)
{
    int res = (y-x)/2;
    if ((x&1) && ((y-x)&1)) res++;
    return res*b;
}

signed main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> q;
        if (a>b) swap(a,b);
        while (q--)
        {
            cin >> l >> r, r++;
            i = (l/b+1)*b, j = (r/b)*b, x=i/b, y=j/b;
            de(l), de(i), de(calc(i,j)), de(j), de(r), dend;
            if (j<i)
            {
                cout << (r-l)*(y&1) << '\n';
            }
            else
            {
                int res = 0;
                if (!x&1) res += (i-l);
                if (y&1) res += r-j;
                res += calc(x,y);
                cout << res << '\n';
            }
        }
        cout << '\n';
    }
}