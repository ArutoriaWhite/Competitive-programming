#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

int n, q;

namespace ST
{
    int st[N<<1], tag[N<<1];
    inline void build()
    {
        memset(tag,-1,sizeof(tag));
        for (int i=0; i<n; i++) cin >> st[i+n];
    }
    inline void upd (int i, int x)
    {
        if (i < n) tag[i] = x;
        else st[i] = x;
    }
    inline void push (int i)
    {
        for (int h=__lg(n); h>0; h--)
        {
            int p = i>>h;
            if (tag[p]==-1) continue;
            upd(p<<1,tag[p]);
            upd(p<<1|1,tag[p]);
            tag[p] = -1;
        }
    }
    inline void modify (int l, int r, int x)
    {
        push(l+n), push(r-1+n);
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) upd(l++,x);
            if (r&1) upd(--r,x);
        }
    }
    inline int query (int p)
    {
        push(p+n);
        return st[p+n];
    }
}

int main()
{
    Eriri
    cin >> n, ST::build();
    cin >> q;
    for (int i=0,r,x; i<q; i++)
    {
        cin >> r >> x;
        ST::modify(0,r,x);
    }
    for (int i=0; i<n; i++)
        cout << ST::query(i) << ' ';
    cout << '\n';
}