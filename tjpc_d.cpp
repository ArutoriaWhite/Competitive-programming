#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int s, t, x, n, k;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x >> k;
        s = t = 0;
        while (x%2 == 0) x/=2, s++;
        while (x%3 == 0) x/=3, t++;
        if (x==1 && t>=s && t-s <= k)
            cout << "Yes\n";
        else cout << "No\n";
    }
}