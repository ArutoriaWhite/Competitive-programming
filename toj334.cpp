#include <iostream>
#include <unordered_map>
#include <functional>
#define level(k) (__lg(k.r-k.l+1))
using namespace std;
typedef long long LL;
const int LOG = 40;

struct rec {LL u, d, l, r;} q;
unordered_map<rec,LL,> ans[LOG];
inline LL qpow (LL x, LL n)
{
    for (LL t[]={1,x},r=1; n>=0; r*=t[n&1],n>>=1,t[1]*=t[1])
        if (n==0) return r;
}
inline rec convq (const rec &k)
{
    rec res = { max(k.u, q.u),
                min(k.d, q.d),
                max(k.l, q.l),
                min(k.r, q.r) };
    return rec {res.u-k.u+1, res.d-k.u+1, res.l-k.l+1, res.r-k.l+1};
}
inline LL query (const rec &k)
{
    int l = level(k);
    rec c = convq(k);
    if (ans[l].find(c)==ans[l].end()) return -1;
    else return ans[l][c];
}
LL dfs (rec k)
{
    LL res = query(k);
    if (res<0)
    {
        if (q.d<k.u || k.d<q.u || q.r<k.l || k.r<q.l) res = 0;
        else if (q.u<=k.u&&k.d<=q.d && q.l<=k.l&&k.r<=q.r) res = qpow(3,__lg(k.r-k.l+1));
        else
        {
            LL xm = (k.l+k.r)>>1, ym = (k.u+k.d)>>1;
            res = dfs({k.u,ym,k.l,xm}) + dfs({ k.u,ym,xm+1,k.r}) + dfs({ym+1,k.d,k.l,xm});
        }
        ans[level(k)][convq(k)] = res;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> q.l >> q.u >> q.r >> q.d;
    cout << dfs(rec{1,(1L<<39),1,(1L<<39)}) << '\n';
}