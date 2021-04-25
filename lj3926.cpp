#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define pb push_back
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
using namespace std;
typedef pair<int,int> pii;

int a, c, p, q, r, x;

inline int CEIL (int i, int j)
{
    if (i%j == 0) return i/j;
    return i/j+1;
}

signed main()
{
    cin >> a >> c >> p >> q >> r >> x;
    int l1, l2; // <= l1 is solid, l1<x<=l2 is melting, <l2 is water

    if (a > c)
    {
        a += x/r;
        cout << a << '\n';
    }
    else
    {
        l1 = (c-a)*p;
        l2 = l1+q;

        if (x <= l1)
        {
            cout << a+(x/p) << '\n';
        }
        else if (x <= l2)
        {
            cout << c << '\n';
        }
        else
        {
            cout << (x-l2)/r + c << '\n';
        }
    }
}
