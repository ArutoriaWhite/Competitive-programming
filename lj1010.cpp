#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

inline void sol (int n)
{
    for (int i=15,f=1; i>=0; i--)
    {
        if (1<<i <= n)
        {
            n -= 1<<i;
            if (f) f=0;
            else cout << '+';
            if (i == 0) cout << "2(0)";
            else if (i==1) cout << "2";
            else cout << "2(", sol(i), cout << ")";
        }
    }
}

int main()
{
    int x; cin >> x;
    sol(x), cout << '\n';
}