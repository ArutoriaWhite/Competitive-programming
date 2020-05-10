#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
const int N = 2e6+10;

int n, t;
char opr;
namespace ST
{
    int st[N<<1];
    inline void build()
    {
        for (int i=0; i<n; i++) cin >> st[i+n];
        for (int i=n-1; i>0; i--) st[i] = max(st[i<<1],st[i<<1|1]);
    }
    inline void modify (int p, int x)
    {
        for (st[p+=n]=x; p>1; p>>=1)
            st[p>>1] = max(st[p],st[p^1]);
    }
    inline int query (int l, int r)
    {
        int res = INT_MIN;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) res = max(res,st[l++]);
            if (r&1) res = max(res,st[--r]);
        }
        return res;
    }
}

int main()
{
    Eriri;
    cin >> n;
    ST::build();
    cin >> t;
    for (int i=0,a,b; i<t; i++)
    {
        cin >> opr >> a >> b;
        if (opr == 'Q')
        {
            if (a > b) swap(a,b);
            cout << ST::query(a-1,b)/2 << '\n';
        }
        else ST::modify(a-1,b);
    }
}