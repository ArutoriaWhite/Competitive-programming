#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

int n, m, t, l, r;
int k[N], d[N];

int main()
{
    cin >> n >> m >> t;
    for (int i=0; i<n; i++)
        cin >> k[i];
    for (int i=0; i<t; i++)
        cin >> d[i];
    l = 0, r = n;
    int p = 0;
    for (int i=0; i<t; i++)
    {
        p += d[i];
        p += k[p];

        r -= m;
        l += m;
        if (p == n-1)
        {
            cout << "Winner Penguin\n";
            cout << "Survived " << i+1 << " rounds\n";
            return 0;
        }        
        if (!(l<=p && p<=r))
        {
            cout << "Dumb Dumb Penguin\n";
            cout << "Survived " << i+1 << " rounds\n";
            return 0;
        }
    }
}
/*
5 5 2
3 4 0 1 2
3 3
*/