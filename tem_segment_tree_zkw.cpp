#include<iostream>
#include<string.h>
using namespace std;
const int N = 1<<18;

int st[N<<1], n, m;

inline void build()
{
    memset(st,0,sizeof(st));
    for (int i=n; i<(n<<1); i++) cin >> st[i];
    for (int i=n-1; i>0; i--) st[i] = max( st[i<<1], st[i<<1|1] );
}

inline void modi (int i, int x)
{
    for (st[i+=n]=x; i>1; i>>=1)
        st[i>>1] = max( st[i], st[i^1] );
}

inline int que (int l, int r)
{
    int res = -1e9;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1)
    {
        if (l&1) res = max( res, st[l++]);
        if (r&1) res = max( res, st[--r]);
    }
    return res;
}

