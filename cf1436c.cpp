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
const int N =1010, M = 1e9+7;

int c[N][N], fac[N];
int gcnt, lcnt, any;
int n, x, pos;

inline void build()
{
    rep(i,0,N-1) c[i][0]=1;
    rep(i,1,N-1)
        rep(j,1,N-1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
    fac[1] = fac[0] = 1;
    rep(i,1,N-1) fac[i]=(fac[i-1]*i)%M;
}

void sol (int l, int r)
{
    int m = (l+r)/2;
    if (l>=r) return;
    if (pos<=m) gcnt++, any--, sol(l,m);
    else
    {
        any--;
        if (m+1!=pos) lcnt++;
        sol(m+1,r);
    }
}

signed main()
{
    build();
    cin >> n >> x >> pos;
    any = n;
    pos++;
    sol(0,n);
    cout << c[n-x][gcnt]*fac[gcnt]%M*c[x-1][lcnt]%M*fac[lcnt]%M*fac[any]%M << '\n';
    //de(gcnt), de(lcnt), de(any), dd;
}