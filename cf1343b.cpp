#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n, t;

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n%4 == 0)
        {
            cout << "YES\n";
            for (int i=2; i<=n; i+=2) cout << i << ' ';
            for (int i=1,j=0; j<(n/2)-1; i+=2,j++) cout << i << ' ';
            cout << n-1+(n/2) << '\n';
        }
        else
        {
            cout << "NO\n";
        }
    }

}