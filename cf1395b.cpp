#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    XinAi
    int n, m, x, y, end;
    cin >> n >> m >> x >> y;
    for (int i=y; i>0; i--)
        cout << x << ' ' << i << '\n';
    for (int i=y+1; i<=m; i++)
        cout << x << ' ' << i << '\n';
    for (int i=x-1; i>0; i--)
    {
        if ((x - i)&1)
        {
            for (int j=m; j>0; j--)
                cout << i << ' ' << j << '\n';
            end = 1;
        }
        else
        {
            for (int j=1; j<=m; j++)
                cout << i << ' ' << j << '\n';
            end = m;
        }
    }
    for (int i=x+1; i<=n; i++)
    {
        if (((i-x)&1 && end==1) || (!((i-x)&1) && end==m))
        {
            for (int j=1; j<=m; j++)
                cout << i << ' ' << j << '\n';
        }
        else
            for (int j=m; j>0; j--)
                cout << i << ' ' << j << '\n';        
    }
}