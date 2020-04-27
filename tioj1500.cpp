#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e4+10;

Pii pos[N], tmp[N], area[N];
int n, q;
double res;

inline double dis (Pii &a, Pii &b) { return sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S)); }
inline bool cmpx (Pii &a, Pii &b) { return a.F < b.F; }
inline bool cmpy (Pii &a, Pii &b) { return a.S < b.S; }
inline void f (int l, int r)
{
    if (r-l<=1) return;
    
    int m = (l+r)>>1, midx = pos[m].F;
    f(l,m), f(m,r);
    merge(pos+l,pos+m,pos+m,pos+r,tmp+l,cmpy);
    for (int i=l; i<r; i++) pos[i] = tmp[i];

    q = 0;
    for (int i=l; i<r; i++)
        if (abs(pos[i].F - midx) < res)
            area[q++] = pos[i];
    for (int i=0; i<q; i++)
        for (int j=i-1; j>=0 && pos[i].S-pos[j].S<res; j--)
            res = min( res, dis(pos[i],pos[j]));
}

signed main()
{
    Eriri
    while (cin >> n)
    {
        res = 1e19;
        for (int i=0; i<n; i++)
            cin >> pos[i].F >> pos[i].S;
        sort(pos,pos+n,cmpx);
        f(0,n);
        cout << res << '\n';    
    }
}