#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1200;

int a[N][N], cnt[N][N], mx, my;

int main()
{
    cin >> my >> mx;
    for (int y=1; y<=my; y++)
        for (int x=1; x<=mx; x++)
            cin >> a[x][y];
    for (int y=1; y<=my; y++)
        for (int x=1; x<=mx; x++)
            for (int i=-1; i<=1; i++)
                for (int j=-1; j<=1; j++)
                {
                    if (i==0 && j == 0) continue;
                    cnt[x][y] += a[x+i][y+j];
                }
    for (int y=1; y<=my; y++)
    {
        for (int x=1; x<=mx; x++)
            cout << cnt[x][y] << ' ';
        cout << '\n';
    }
}