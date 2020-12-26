#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+10, M =  998244353;

struct P {int x, type;};
int n, k, t, infac[N], fac[N];

inline int cmp (P i, P j)
{
    if (i.x != j.x) return i.x < j.x;
    return i.type > j.type;
}
inline int qpow (int i, int j)
{
    int res=1;
    for (; j; j>>=1,i=(i*i)%M)
        if (j&1) res = res*i%M;
    return res;
}
inline void buildC()
{
    fac[0] = infac[0] = 1;
    rep(i,1,N-1) fac[i] = fac[i-1]*i%M;
    rep(i,1,N-1) infac[i] = qpow(fac[i], M-2);
}
inline int C (int i, int j)
{
    if (i<j) return 0;
    return fac[i]*infac[j]%M*infac[i-j]%M;
}

signed main()
{
    haaachamachama
    buildC();
    vector<P> p;
    cin >> n >> k;
    rep(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        p.push_back({u,1});
        p.push_back({v,0});
    }
    sort(p.begin(), p.end(), cmp);

    int c=0, res=0;
    for (auto e: p)
    {
        int tp=e.type;
        if (tp)
        {
            res = (res+C(c,k-1))%M;
        }
        c += (tp? 1 : -1);
    }
    cout << res << '\n';
}