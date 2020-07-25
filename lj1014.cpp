#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n, m, x, y;

int main()
{
    cin >> n;
    for (int i=1; n-i>0; i++)
        n -= i, m++;
    if (m&1)
    {
        x = 0, y = m+2;
        while (n--)
            x++, y--;
    }
    else
    {
        x = m+2, y = 0;
        while (n--)
            x--, y++;
    }
    cout << x << '/' << y << '\n';
}