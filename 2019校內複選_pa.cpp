#include<bits/stdc++.h>
using namespace std;
#define IMP (-1)
#define maxN (6000)
#define maxQ (1000000)

#define int long long

struct Q{
    int l, r, id;
    int m, od;

    inline bool operator < ( const Q &b)
    {
    //same time od
        if( m==b.m)
        {
            if( b.od) return true;
            return l > b.l;
        }
        return m<b.m;
    }

} qs[maxQ];

int ans[maxQ];

int A[maxN], B[maxN];

int cL, cR, cAns;
int cM, cOd;

inline void add()
{
    cL--, cR++;
    cAns += abs(A[cL]-B[cR]) + abs(A[cR]-B[cL]);
}
inline void reCalc( int l, int r, int m, int od)
{
    cAns=0;
    for( int i=l, j=r; i<=r; i++, j--){
        cAns += abs( A[i]-B[j]);
    }
}

signed main()
{
    #ifdef local
        freopen("in","r",stdin);
    #else
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(0);
    #endif

    int n,m; cin >> n >> m;
    for( int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    for( int i=0; i<n; i++)
    {
        cin >> B[i];
    }
    for( int i=0; i<m; i++)
    {
        int l, r; cin >> l >> r;
        qs[i] = Q{ --l, --r, i, (l+r)>>1, (l+r)&1};
    }
    sort( qs, qs+m);

    cM=cOd=IMP;
    for( int i=0; i<m; i++)
    {
        Q &q=qs[i];

        if( cM==q.m && cOd==q.od)
        {
            while( cL>q.l) add();
        }
        else
        {
            reCalc( q.l, q.r, q.m, q.od);
            cM=q.m, cOd=q.od;
        }
        ans[q.id] = cAns;
    }

    for( int i=0; i<m; i++)
    {
        cout << ans[i] << '\n';
    }
}
