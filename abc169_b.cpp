#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int a[N];

signed main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++)
    {
        if (a[i] == 0)
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    __int128 res = 1;
    for (int i=0; i<n; i++)
    {
        res *= a[i];
        if (res > (int)1e18)
        {
            cout << -1 << '\n';
            return 0;
        }
    }
    int owo = res;
    cout << owo << '\n';
}
/*
x * res > 1e18
*/