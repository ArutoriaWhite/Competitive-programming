#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;

int n, k, t, a, mx;

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        mx = 0;
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> a, mx = max(a,mx);
        if (mx > k) cout << -1 << '\n';
        else
        {
            cout << n*k << '\n';
            for (int i=0; i<n; i++)
                for (int j=1; j<=k; j++)
                    cout << j << ' ';
            cout << '\n';
        }
    }
}