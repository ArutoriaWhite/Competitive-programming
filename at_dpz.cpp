#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define shaaark ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;
/*
rep(i,1,n)
{
    dp[i] = query_min(h[i]) + h[i]*h[i] + c
    insert(line{m=-2*h[i], k=h[i]*h[i]+dp[i]})
}
*/
int n, h[N], c, dp[N];

int r;
struct Line
{
    int m, k;
    double lbound=0;
} dq[N];

inline double interx (Line a, Line b)
{
    return (double)(b.k-a.k)/(a.m-b.m);
}
inline void insert (int m, int k)
{
    while (r>1 && interx({m,k,0},dq[r-2]) < interx(dq[r-1],dq[r-2])) r--;
    dq[r] = {m,k,interx({m,k,0},dq[r-1])};
    r++;
}
inline int query (int x)
{
    int i=0, s=r;
    while (s>0)
    {
        if (i+s>=r || dq[i+s].lbound>x)
            s >>=1 ;
        else i += s;
    }
    return dq[i].m*x + dq[i].k;
}

signed main()
{
    shaaark
    cin >> n >> c;
    rep(i,1,n) cin >> h[i];
    insert(-2*h[1], h[1]*h[1]);
    rep(i,2,n)
    {
        dp[i] = query(h[i]) + h[i]*h[i] + c;
        insert(-2*h[i], h[i]*h[i]+dp[i]);
    }
    cout << dp[n] << '\n';
}