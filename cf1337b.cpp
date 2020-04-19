#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int t, h, n, m;

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> h >> n >> m;
        while (h < 2*h-20 && n>0)
            h = h/2+10, n--;
        cout << (h<=m*10? "YES" : "NO") << '\n';
    }
}