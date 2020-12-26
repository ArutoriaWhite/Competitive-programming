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
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int n, a[N];
string s;
priority_queue<int,vector<int>,greater<int>> pq[30];

struct ST
{
    int lz[N<<2];
    inline void add (int l, int r)
    {
        l--;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) lz[l++]++;
            if (r&1) lz[--r]++;
        }
    }
    inline int query (int p)
    {
        int res=0;
        for (p=p+n-1; p>0; p>>=1)
            res += lz[p];
        return res;
    }
} st;

signed main()
{
    SakuraMyWife
    cin >> n >> s;
    rep(i,1,n) a[i]=s[i-1]-'a';
    rep(i,1,n) pq[a[i]].push(i);
    int res=0;
    for (int i=n,j=1; i; i--,j++)
    {
        int v = pq[a[i]].top(); pq[a[i]].pop();
        int u= v + st.query(v);
        st.add(1,v);
        res += u-j;
    }
    cout << res << '\n';
}