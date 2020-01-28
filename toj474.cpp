#include <iostream>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int T, n, m, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        long long A = max(0,m-k+1), B = max(0,n-k+1);
        cout << A*n+B*m+A*B*2 << '\n';
    }
}
/*
5
3 3 3
3 3 2
4 4 3
4 2 6
6 9 5
*/