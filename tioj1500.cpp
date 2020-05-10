#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 210;

int a[N][N], h[N][N], w[N], mx, my, res;

int main()
{
    Eriri
    cin >> my >> mx;
    for (int y=0; y<my; y++)
        for (int x=0; x<mx; x++)
            cin >> a[x][y];
    for (int x=0; x<mx; x++)
        for (int y=my-1; y>=0; y--)
            h[x][y] = (h[x][y+1]+1)*a[x][y];
    for (int y=0; y<my; y++)
        for (int k=1; k<=my; k++)
            for (int x=1; x<=mx; x++)
                w[x] = (w[x-1]+1)*(h[x-1][y]>=k), res = max(res, w[x]*k);
    cout << res << '\n';
}