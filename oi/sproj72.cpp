#include <iostream>
#include <iomanip>
using namespace std;
const long double EPS  = 1e-7;
const int N = 15;

long double a[N], b[N], c[N];
int T, n;
inline long double query (long double t)
{
    long double maxval=-1e20;
    for (int i=0; i<n; i++)
        maxval = max( a[i]*(t-b[i])*(t-b[i])+c[i] ,maxval);
    return maxval;
}
inline long double bs()
{
    long double l=0, r=305;
    while (l+EPS<r)
    {
        long double ml = l+(r-l)/3, mr = r-(r-l)/3;
        if (query(ml)>query(mr)) l=ml;
        else r=mr;
    }
    return query((l+r)/2);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i] >> b[i] >> c[i];
        cout << fixed << setprecision(5) << bs() << '\n';
    }
}
/*
2
2
0.00111831 1 1
0.00111831 299 1
2
0 1 1
0 299 -123.67899
*/
