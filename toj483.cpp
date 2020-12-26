#include <bits/stdc++.h>
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

struct D {int l=0, m=0, r=0;} st[N<<1];
int n, q;

inline int empty (D x) {return x.m==-1;}
inline D merge (D A, D B)
{
    if (empty(A)&&empty(B)) return {max(A.l,B.r), -1, max(A.l,B.r)};
    if (empty(A)) A.l = max(A.l,B.l), A.m=A.r=B.l=0;
    if (empty(B)) B.r = max(A.r,B.r), B.m=A.r=B.l=0;
    return {A.l, A.m+B.m+max(A.r,B.l), B.r};
}
inline void update (int p)
{
    for (p+=n; p>1; p>>=1)
        st[p>>1] = merge(st[min(p,p^1)],st[max(p,p^1)]);
}
inline int query (int l, int r)
{
    D L, R, res;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if (l&1) L = merge(L, st[l++]);
        if (r&1) R = merge(st[--r], R);
    }
    res = merge(L,R);
    return (empty(res)? res.l : res.l+res.m+res.r);
}

signed main()
{
    XinAi
    cin >> n >> q;
    for (int i=0,a; i<n; i++)
        cin>>a, st[i+n] = (i==n-1? D{a,0,0} : D{a,-1,a});
    for (int i=0; i<n; i++) update(i);
    for (int i=0,a,b,c; i<q; i++)
    {
        cin >> a;
        if (cin>>b, b--, a==1)
            st[b+n].m=st[b+n].r=0;
        else if (a==2)
        {
            st[b+n].r=st[b+n].l;
            st[b+n].m=-1;
        }
        else if (cin>>c, a==3)
        {
            if (empty(st[b+n]))
                st[b+n].l=st[b+n].r=c;
            else st[b+n].l=c;
        }
        else cout << query(b,c) << '\n';
        update(b);
    }
}