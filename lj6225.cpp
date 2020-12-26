#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
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
struct ST
{
    int tr[N<<1];
    inline void build()
    {
        for (int i=0; i<n; i++) cin >> tr[i+n];
        for (int i=n-1; i>0; i--) tr[i]=tr[i<<1]^tr[i<<1|1];
    }
    inline void modify (int p, int x)
    {
        for (tr[p+=n]=x; p>1; p>>=1)
            tr[p>>1] = tr[p]^tr[p^1];
    }
    inline int query (int l, int r)
    {
        int res = 0;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) res ^= tr[l++];
            if (r&1) res ^= tr[--r];
        }
        return res;
    }
} st;

signed main()
{
    SakuraMyWife
    cin >> n >> q;
    st.build();
    for (int i=0,a,b,c; i<q; i++)
    {
        cin >> a >> b >> c;
        if (a==1) st.modify(b-1,c);
        else cout << st.query(b-1,c) << '\n';
    }
}