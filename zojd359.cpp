#include <iostream>
using namespace std;
const int N = 5e5, K = 30;
int st[K][N], n, m;

int build ()
{
    for (int i=0; i<n; i++)
        cin >> st[0][i];
    for (int j=1; (1<<j)<=n; j++)
        for (int i=0; i+(1<<j)<=n; i++)
            st[j][i] = max(st[j-1][i], st[j-1][i+(1<<(j-1))]);
}
int query (int l, int r)
{
    int j; for (j=0; (1<<(j+1))<=(r-l); j++);
    return max( st[j][l], st[j][r-(1<<j)]);
}

int main ()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while (cin >> n)
    {
        build();
        cin >> m;
        for (int i=0,l,r; i<m; i++)
        {
            cin >> l >> r;
            cout << query(l,r) << '\n';
        }
    }
}
