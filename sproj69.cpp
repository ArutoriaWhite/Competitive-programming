#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int R = 2e8, N = 1e4+10;

int eni[N], ori[N], a[N], n, k, T;
LL tsu[N];

inline bool can (int d)
{
    for (int i=0; i<n; i++)
        tsu[i] = ori[i]+(LL)a[i]*d;
    sort(tsu,tsu+n);
    for (int i=0,j=n-k; i<k; i++,j++)
        if (eni[i]>=tsu[j]) return 0;
    return 1;
}
inline int bs ()
{
    int i=0, s=R;
    if (!can(s)) return -1;
    while (s>0)
    {
        if (can(i+s)) s>>=1;
        else i+=s;
    }
    if (can(i)) return i;
    else return i+1;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> ori[i] >> a[i];
        for (int i=0; i<n; i++)
            cin >> eni[i];
        sort(eni,eni+n);
        cout << bs() << '\n';
    }
}