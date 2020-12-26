#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

int a;

inline int can (int x)
{
    if (x > a) return 0;
    return x*(x+1)/2 <= a;
}

inline int bs ()
{
    int s = (1e8), i = 0;
    while (s > 0)
    {
        if (!can(s+i))
            s>>=1;
        else
            i += s;
    }
    return i;
}

signed main ()
{
    cin >> a;
    cout << bs() << '\n';
}