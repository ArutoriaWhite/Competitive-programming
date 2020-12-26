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
const int N = 110;

int t, n, a[N];

signed main()
{
    XinAi
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=n-1; i>=0; i--) cout << a[i] << ' ';
        cout << '\n';
    }
}