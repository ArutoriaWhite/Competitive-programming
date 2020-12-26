#include <bits/stdc++.h>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;
int n, m;
pii a[N];

int legal (int x)
{
    vector<pii> vl, vm, vr;
    rep(i,1,n)
    {
        if (a[i].S<x) vl.push_back(a[i]);
        if (x<a[i].F) vr.push_back(a[i]);
        if (a[i].F<=x&&x<=a[i].S) vm.push_back(a[i]);
    }
    int k=0;
    while (SZ(vl)<n/2 && k<SZ(vm)) vl.push_back(vm[k++]);
    while (SZ(vr)<n/2 && k<SZ(vm)) vr.push_back(vm[k++]);
    if ((SZ(vl)<n/2) || (SZ(vr)<n/2) || (k>=SZ(vm))) return 0;
    sort(vl.begin(), vl.end());
    sort(vr.begin(), vr.end());
    int cost=x;
    for (int i=0; i<n/2; i++)
    {
        cost += vl[i].F;
        cost += max(x, vr[i].F);
    }
    return cost <= m;
}
int bs (int i)
{
    int s=1e9+10;
    while (s>0)
    {
        if (legal(i+s)) i += s;
        else s >>= 1;
    }
    return i;
}

signed main()



''
{
    shaaark
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,1,n) cin >> a[i].F >> a[i].S;
        sort(a+1,a+1+n);
        cout << bs(a[(n+1)/2].F) << '\n';
    }
}