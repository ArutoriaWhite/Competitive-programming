#pragma optimize ("O3")
#include <iostream>
#include <map>
#include <tuple>
#define u(x) (get<0>(x))
#define d(x) (get<1>(x))
#define l(x) (get<2>(x))
#define r(x) (get<3>(x))
#define lev(x) (__lg(r(x)-l(x)+1))
#define DE cout << " ::"
using namespace std;
typedef long long LL;
typedef tuple<LL,LL,LL,LL> rec;
const int LOG = 40;

map<rec,LL> ans[LOG];
rec q;

inline LL qpow (LL x, LL n)
{
    for (LL t[]={1,x},r=1; n>=0; r*=t[n&1],t[1]*=t[1],n>>=1)
        if (n==0) return r;
}
inline rec conv (const rec &k)
{
    return rec{ max(u(q),u(k))-u(k)+1,
                min(d(q),d(k))-u(k)+1,
                max(l(q),l(k))-l(k)+1,
                min(r(q),r(k))-l(k)+1 };
}
inline LL query (const rec &k)
{
    rec c = conv(k);
    if (ans[lev(k)].find(c)==ans[lev(k)].end())
        return -1;
    return ans[lev(k)][c];
}
LL dfs (rec k)
{
    LL res = query(k);
    if (res<0)
    {
        if (l(q)<=l(k)&&r(k)<=r(q) && u(q)<=u(k)&&d(k)<=d(q))
            res = qpow(3,lev(k));
        else if (r(q)<l(k) || r(k)<l(q) || d(q)<u(k) || d(k)<u(q))
            res = 0;
        else
        {
            LL xm = (l(k)+r(k))>>1, ym = (u(k)+d(k))>>1;
            res = dfs({u(k),ym,l(k),xm}) + dfs({u(k),ym,xm+1,r(k)}) + dfs({ym+1,d(k),l(k),xm});
        }
        ans[lev(k)][conv(k)] = res;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> l(q) >> u(q) >> r(q) >> d(q);
    cout << dfs( rec{1,(1L<<39),1,(1L<<39)} ) << '\n';
}