#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define NewYearBurst ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1000;

int row[N], col[N], rowmx, colmx;
int r, c, n, q;

signed main()
{
    NewYearBurst
    cin >> r >> c >> n >> q;
    for (int i=1,x,y; i<=n; i++)
    {
        cin >> x >> y;
        row[x]++, col[y]++;
        rowmx = max(rowmx, row[x]);
        colmx = max(colmx, col[y]);
    }
    for (int i=1,t,a,b; i<=q; i++)
    {
        cin >> t;
        if (t == 3)
            cout << colmx << '\n';
        else if (t == 4)
            cout << rowmx << '\n';
        else if (cin >> a >> b, t == 1)
        {
            for (int j=a; j<b; j++)
                col[b] += col[j], col[j] = 0;
            colmx = max(colmx, col[b]);
        }
        else if (t == 2)
        {
            for (int j=a; j<b; j++)
                row[b] += row[j], row[j] = 0;
            rowmx = max(rowmx, row[b]);
        }
    }
}