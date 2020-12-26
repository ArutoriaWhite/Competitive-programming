#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

int a[1000000];

signed main()
{
    int n;
    int res = 0;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=1; i<n; i++)
    {
        if (a[i] < a[i-1])
        {
            res += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << res << '\n';
}