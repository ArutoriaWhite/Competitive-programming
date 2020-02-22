#include <bits/stdc++.h>
#define mem(a,x) memset(a,x,sizeof(a));
#define Excalibur ios::sync_with_stdio(0), cin.tie(0);
#define qsum(l,r,k) (sum[r][k]-sum[l][k])
using namespace std;
const int N = 8e4+10, B = 300;

int a[N], b[N], blo[N], sum[B][N], mul[B][B], tmp[N];

int sz, m, n, q, d;

template <typename T> void DE (initializer_list<T> args);

inline void discret()
{
    memcpy(b,a,sizeof(a));
    sort(a,a+n);
    for (int i=0; i<n; i++)
        b[i] = lower_bound(a,a+n,b[i])-a;
}
inline void split()
{
    sz = sqrt(n-1)+1;
    for (int i=0; i<n; i++)
        blo[i] = (i/sz)+1, m=blo[i];
}
inline void build_sum()
{
    for (int i=0; i<n; i++)
        sum[blo[i]][b[i]]++;
    for (int i=1; i<=m; i++)
        for (int j=0; j<n; j++)
            sum[i][j] += sum[i-1][j];
}
inline void build_mul()
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++)
        {
            mul[i][j] = mul[i][j-1];
            for (int k=(j-1)*sz; blo[k]==j&&k<n; k++)
                mul[i][j] = max(mul[i][j],qsum(i,j,b[k]));
        }
}
inline void deal(int &l,int &r)
{
    l--,r--,l-=d,r-=d;
}
inline int query (int l, int r)
{
    deal(l,r);
    int res = 0;
    memset(tmp,0,sizeof(tmp));

    if (blo[l] == blo[r])
    {
        DE({"l","r"});
        DE({l, r});
        for (int i=l; i<=r; i++)
            res = max( ++tmp[b[i]], res);
    }
    else
    {
        DE({"l","Bl","Br","r"});
        DE({l,blo[l],blo[r]-1,r});
        res = mul[blo[l]][blo[r]-1];
        for (int i=l; blo[i]==blo[l]; i++)
            res = max( ++tmp[b[i]]+qsum(blo[l],blo[r]-1,b[i]), res);
        for (int i=(blo[r]-1)*sz; i<=r && i<n; i++)
            res = max( ++tmp[b[i]]+qsum(blo[l],blo[r]-1,b[i]), res);
    }
    return res;
}

// dbg
template <typename T> void DE (initializer_list<T> args)
{
    /*
    cout << " ::";
    for (auto x: args)
        cout << setw(3) << x << ' ';
    cout << '\n';
    //*/
}
inline void print_blo()
{
    DE({"print_blo"});
    for (int i=0; i<n; i++)
        DE({i,blo[i]});
    DE({"m","sz"});
    DE({m,sz});
}
inline void print_sum()
{
    DE({"print_sum"});
    int l, r;
    while (cin >> l >> r)
    {
        for (int k=0; k<n; k++)
        {
            if (qsum(l,r,k)>0)
                DE({k,qsum(l,r,k)});
        }
    }
}
inline void print_mul()
{
    DE({"print_mul"});
    int l, r;
    while (cin >> l >> r)
        DE({mul[l][r]});
}

signed main()
{
    Excalibur;
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> a[i];
    discret();
    split();
    print_blo();
    build_sum();
    build_mul();
    for (int i=0,l,r; i<q; i++)
    {
        cin >> l >> r;
        cout << (d=query(l,r)) << '\n';
    }
}
