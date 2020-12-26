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

int sol (int a, int b, int x, int y, int n)
{
    int a2 = max(x, a-n);
    n -= a-a2;
    b = max(y, b-n);
    return a2*b;
}
signed main()
{
    XinAi
    int t, a, b, x, y, n;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> x >> y >> n;
        cout << min(sol(a,b,x,y,n), sol(b,a,y,x,n)) << '\n';
    }
}