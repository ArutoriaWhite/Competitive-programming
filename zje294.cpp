#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;

int x, a[20], n, p, res;

inline int find_e()
{
    for (int i=n-1; i>=0; i--)
        if (!(a[i]&1)) return i;
    return -1;
}

signed main()
{
    Eriri
    while (cin >> x)
    {
        memset(a,0,sizeof(a));
        n = 0;
        p = 0;
        res = 2e18;
        for (int t=x; t; t/=10)
            a[n++] = t%10;
        p = find_e();
        if (p==-1)
            res = 0;
        if (n>=2 && a[n-1]==1 && a[n-2]==0)
        {
            int t;
            for (t=1; t*10<=x; t*=10);
            res = min(res, abs(x-(t-1)));
        }
        if (a[p] == 0)
        {
            int t=0;
            for (int i=n-1; i>p; i--)
                t*=10, t+=a[i];
            t = t*10+1;
            for (int i=0; i<p; i++,t=(t*10+1));
            res = min(res, abs(x-t));
        }
        if (a[p] > 0)
        {
            int t1=0, t2=0;
            for (int i=n-1; i>=p; i--)
                t1*=10, t2*=10, t1+=a[i], t2+=a[i];
            t1--, t2++;
            for (int i=0; i<p; i++)
                t1 = (t1*10+9), t2 = (t2*10+1);
            res = min(res, abs(x-t1));
            res = min(res, abs(x-t2));
        }
        cout << res << '\n';
    }
}