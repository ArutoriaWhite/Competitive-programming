#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

int a[N], pre[N<<1], n, k, t, res;

inline void init()
{
    for (int i=0; i<=(k<<1)+10; i++) pre[i] = 0;
    res = 1e9;
}

inline void add (int l, int r, int x)
{
    pre[l] += x, pre[r+1] -=x;
}

inline void calc ()
{
    for (int i=1,j=n; i<j; i++,j--)
    {
        int l = min(a[i],a[j])+1, r = max(a[i],a[j])+k;
        add(2,2*k,2), add(l,r,-1), add(a[i]+a[j],a[i]+a[j],-1);
    }
    for (int i=2; i<=2*k; i++)
        pre[i] += pre[i-1], res = min(res, pre[i]);
}

int main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i=1; i<=n; i++) cin >> a[i];
        init(), calc();
        cout << res << '\n';
    }
}