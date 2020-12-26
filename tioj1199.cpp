#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

int qpow (int a, int b, int m)
{
    int res;
    for (res=1; b; b>>=1,a=(a*a%m))
        if (b&1) res = (res*a)%m;
    return res;
}
signed main()
{
    XinAi
    int a, b, c;
    while (cin >> a >> b >> c, (a||b||c))
    {
        int res = 0;
        rep(i, 0, c-1)
        {
            if (i==0 && b==0) continue;
            if (qpow(i, b, c) == a) res++;
        }
        cout << res << '\n';
    }
}
