#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

signed main()
{
    int n, k, a;
    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> a;
        a = ((a+10)*2)*((a+10)*2);
        if (a > k)
        {
            cout << "BURST!!!\n";
            break;
        }
        else
        {
            cout << a << '\n';
        }
    }

}
