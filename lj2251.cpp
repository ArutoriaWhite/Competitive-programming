#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

Pii q[N];
int f, r, n, m;

int main()
{
    Eriri
    cin >> n >> m;
    for (int i=0,x; i<n; i++)
    {
        cin >> x;
        while (q[r-1].F > x) r--;
        q[r++] = {x,i};
        if (i+1-m>=0)
        {
            if (q[f].S < i+1-m) f++;
            cout << q[f].F << '\n';
        }
    }
}