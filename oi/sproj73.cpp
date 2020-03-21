#include <iostream>
using namespace std;
const int N = 1e5;

int work[N], m, n, T;

inline bool can (int x)
{
    int i, j;
    for (i=0,j=m; i<n&&j>0; j--)
       for (int k=x; i<n && k-work[i]>=0; k-=work[i++]);
    return i>=n;
}

inline int bs ()
{
    int i=0, s=1e9;
    while (s>0)
    {
        if (can(i+s)) s >>= 1;
        else i += s;
    }
    return i+1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i=0; i<n; i++)
            cin >> work[i];
        cout << bs() << '\n';
    }
}
