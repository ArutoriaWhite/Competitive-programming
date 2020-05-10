#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int mn, mx, n, l;

int main()
{
    cin  >> l >> n;
    for (int i=0,a; i<n; i++)
    {
        cin >> a;
        mn = max(mn,min(a,l-a+1));
        mx = max(mx,max(a,l-a+1));
    }
    cout << mn << ' ' << mx << '\n';
}