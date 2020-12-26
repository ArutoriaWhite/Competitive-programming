#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int n, m, ans;
pii lb[N], ra[N];

int f (int i, int j) // lb, ra
{
    if (lb[i].F>ra[j].F || lb[i].S<ra[j].S) return 0;  
    return (ra[j].F-lb[i].F)*(-ra[j].S+lb[i].S);
}
void sol (int l1, int r1, int l2, int r2)
{
    if (l1 > r1) return;
    if (l1 == r1)
        rep(i,l2,r2)
            ans = max(ans, f(i,l1));
    else
    {
        int m1 = (l1+r1)/2, m2=-1, mxf=0;
        rep(i,l2,r2)
            if (m2==-1 || f(i,m1)>mxf) mxf=f(i,m1), m2=i;
        sol(l1,m1,l2,m2);
        sol(m1+1,r1,m2,r2);
    }        
}


signed main()
{
    shaaark
    cin >> n;
    for (int i=1,len; i<=n; i++)
    {
        cin >> len;
        if (i&1) ra[i] = {ra[i-1].F+len, ra[i-1].S};
        else ra[i] = {ra[i-1].F, ra[i-1].S+len};
    }
    cin >> m;
    for (int i=1,len; i<=m; i++)
    {
        cin >> len;
        if (i&1) lb[i] ={lb[i-1].F, lb[i-1].S+len};
        else lb[i] = {lb[i-1].F+len, lb[i-1].S};
    }
    n--, m--;
    sol(1,n,1,m);
    cout << ans << '\n';
}