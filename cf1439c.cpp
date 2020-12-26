#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int n, q;
int bs1 (int i, int c);
int bs2 (int i, int c);

struct ST
{
    int tr[N<<1], lz[N<<1], sz[N<<1];
    void build()
    {
    }
    void modify (int l, int r, int x) // l to r set to max(a[i], x)
    {
    }
    int query (int l, int r)
    {
    }
} st;

int bs1 (int i, int c) //search the first j that a[i]+...+a[j]>c, i<=j
{
    int s=n;
    while (s>0)
    {
        if (i+s>n || st.query(i,i+s)>c) s>>=1;
        else i+=s;
    }
    return i;
}
int bs2 (int i, int c) //search the first j that a[j]<=c, i<=j
{
    int s=n;
    while (s>0)
    {
        if (i+s>=n || a[i+s]<=c) s>>=1;
        else i+=s;
    }
    return i;
}

int Query (int p, int c)
{
    int res=0;
    while (p<n)
    {
        int j = bs1(p,c);
        res += j-p;
        c -= st.query(p,j);
        p = bs2(j,c);
    }
    return res;
}

signed main()
{
    cin >> n >> q;
    build();
    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t==1) st.modify(0,x,y);
        else cout << Query(x-1,y) << '\n';
    }
}