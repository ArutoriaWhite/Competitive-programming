#include <iostream>
using namespace std;
const int N = 1e6+10;

int p[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int u=1,x; u<n; u++)
        cin >> x, p[u] = x;
    for (int i=0,x,f; i<q; i++)
    {
        cin >> x;
        for (int j=0; j<x; j++)
            cin >> f;
        if (x==1) cout << f << '\n';
        else cout << p[f] << '\n';
    }
}
/*
7 2
0 0 0 2 2 4
3 1 2 3
2 4 5
*/