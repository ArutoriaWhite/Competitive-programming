#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int n, q, a;
struct St
{
    int st[N<<1];
    inline void build()
    {
        for (int i=0; i<n; i++) cin >> st[i+n];
        for (int i=n-1; i>0; i--) st[i] = st[i*2] + st[i*2+1];
    }
    inline int query (int l, int r)
    {
        int res = 0;
        for (l+=n,r+=n; l<r; l>>=1,r>>=1)
        {
            if (l&1) res += st[l++];
            if (r&1) res += st[--r];
        }
        return res;
    }
    inline int modify (int p, int x)
    {
        for (st[p+=n]+=x; p>1; p>>=1)
            st[p/2] = st[p]+st[p^1];
    }
} sg;

inline int calc()
{
    int cnt=0, i=0, s, j;
    while (i<n)
    {
        cnt++;
        j = i, s = n;
        while (s)
        {
            if (j+s>n || sg.query(i,j+s)>a)
                s >>= 1;
            else
                j += s;
        }
        i = j;
    }
    return cnt;
}

signed main()
{
    cout << 2e5*30*__lg(200000)*__lg(200000) << '\n';
    Eriri
    cin >> n >> q >> a;
    sg.build();
    for (int i=0,x,y,z; i<q; i++)
    {
        cin >> x;
        if (x==0)
            cout << calc() << '\n';
        else
        {
            cin >> y >> z;
            sg.modify(y-1,(x==1? z : -z));
        }
    }
}
