#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define pb push_back
#define MID ((l+r)/2)
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

/*
rangement add
rangement query how much node are greater than 1
*/
struct E {int p,u,d,x;};
vector<E> e;
int n;
int st[N<<2], lz[N<<2]; // st[i]:cnt of position greater than 0, lz[i]: cnt layer lies on whole node

void add (int u, int l, int r, int ql, int qr, int x)
{
    if (r<=ql || qr<=l) return;
    if (ql<=l && r<=qr) lz[u] += x;
    else
    {
        if (!(MID<=ql || qr<=l) && (r-l)>1)
            add(u<<1,l,MID,ql,qr,x);
        if (!(r<=ql || qr<=MID) && (r-l)>1)
            add(u<<1|1,MID,r,ql,qr,x);
    }
    st[u] = (lz[u]? r-l : st[u<<1]+st[u<<1|1]);
}

signed main()
{
    ShinraTensei
    cin >> n;
    rep (i,1,n)
    {
        int l, r, u, d;
        cin >> l >> r >> d >> u;
        e.pb({l,u,d,1});
        e.pb({r,u,d,-1});
    }
    sort(e.begin(), e.end(), [](E i, E j){return i.p < j.p;});
    long long ans = 0;
    long long curp = e.begin()->p;
    for (auto i: e)
    {
        ans += (i.p-curp)*st[1];
        add(1,0,N,i.d,i.u,i.x);
        curp = i.p;
    }
    cout << ans << '\n';
}