#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

int t, n;

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int k=3; k<=n; k=k<<1|1)
        {
            if (n%k==0)
            {
                cout << n/k << '\n';
                break;
            }
        }
    }
}
