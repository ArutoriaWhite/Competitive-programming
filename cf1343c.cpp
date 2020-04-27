#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

int arr[N], r, t, n, res;

signed main()
{
    Eriri;
    cin >> t;
    while (t--)
    {
        cin >> n;
        r = res = 0;
        for (int i=0,x; i<n; i++)
        {
            cin >> x;
            if (arr[r-1]*x > 0) arr[r-1] = max( arr[r-1], x);
            else arr[r++] = x;
        }
        for (int i=0; i<r; i++)
            res += arr[i];
        cout << res << '\n';
    }
}