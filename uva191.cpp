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

typedef pair<int,int> V;
V operator | (V p, V q){ return {p.ff-q.ff, p.ss-q.ss}; }
int operator * (V p, V q){ return p.ff*q.ff+p.ss*q.ss; } // dot product
int operator ^ (V p, V q){ return p.ff*q.ss - p.ss*q.ff; } // cross product

int T;
V s, t, r1, r2, r3, r4;
int l, u, r, d;

int inseg (V x, V p, V q)
{
    return (x|p)*(x|q)<=0;
}
int inter (V p, V q, V r, V s)
{
    if (((p|q)^(r|s)) == 0)
    {
        if (inseg(p,r,s) || inseg(q,r,s) || inseg(r,p,q) || inseg(s,p,q))
            return 1;
        else 
            return 0;
    }
    else
    {
        if ( ((p|q)^(p|s))*((p|q)^(p|r)) > 0 )
            return 0;
        if ( ((r|s)^(r|q))*((r|s)^(r|p)) > 0 )
            return 0;
        return 1;
    }
}
int inrec (V p)
{
    return l<=p.ff && p.ff<=r && d<=p.ss && p.ss<=u;
}

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> s.ff >> s.ss >> t.ff >> t.ss;
        cin >> l >> u >> r >> d;

        if (l > r) swap(l,r);
        if (d > u) swap(d,u);
        r1={l,u}, r2={r,u}, r3={r,d}, r4={l,d};

        if (inter(s,t,r1,r2) ||
            inter(s,t,r2,r3) || 
            inter(s,t,r3,r4) || 
            inter(s,t,r4,r1) ||
            inrec(s) || inrec(t))
        {
            cout << "T\n";
        }
        else
        {
            cout << "F\n";
        }
    }    