#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string s;
int n, a, b, c;

int main()
{
    while (cin >> n)
    {
        getline(cin,s);
        a = 1e9, b = -1e9;
        for (int i=1; i<=n; i++)
        {
            getline(cin,s);
            cout << s.size() << '\n';
            a = min(a, (int)s.size());
            b = max(b, (int)s.size());
        }
        cout << a << ' ' << b << ' ' << __gcd(a,b) << '\n';
    }
}