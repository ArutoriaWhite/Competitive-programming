#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

int a[N], inc[N], decr[N], p, q, n;
bool cmp (int a, int b) { return a > b; }

int main()
{
    Eriri
    while (cin >> a[n]) n++;
    for (int i=0; i<n; i++)
    {
        if (!p || inc[p-1]<a[i]) inc[p++] = a[i];
        else *lower_bound(inc,inc+p,a[i]) = a[i];
        if (!q || decr[q-1]>=a[i]) decr[q++] = a[i];
        else *upper_bound(decr,decr+q,a[i],cmp) = a[i];
    }
    cout << q << '\n' << p << '\n';
}