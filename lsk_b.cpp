#include <iostream>
using namespace std;
const int N = 1e6+10;

int x[N], h[N], n;

signed main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x[i];
    }
    for (int i=1; i<=n; i++)
    {
        cin >> h[i];
    }
    int nx=0;
    for (int i=1; i<=n; i++)
    {
        if (nx >= x[i] || i==1)
        {
            nx = max(nx, x[i]+h[i]);
        }
        else
        {
            cout << i-1 << '\n';
            break;
        }
    }
}