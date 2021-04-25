#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define repm(i,j,k) for (int i=j; i>=k; i--)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1010;

int hori[N][N], miya[N][N], a[N][N], n, m, ans;

inline void calc_r()
{
    mem(hori,0);
    repm(i,m,1)
        rep(j,1,n)
            hori[j][i] = hori[j][i+1] + a[j][i+1];
}
inline void calc_l()
{
    mem(hori,0);
    rep(i,1,m)
        rep(j,1,n)
            hori[j][i] = hori[j][i-1] + a[j][i-1];
}
inline void calc_up()
{
    mem(miya,0);
    rep(i,1,m)
    {
        rep(j,1,n)
        {
            miya[j][i] = miya[j-1][i]+hori[j-1][i]*a[j-1][i];
            if (a[j][i]) ans += miya[j][i];
        }
    }
}
inline void calc_down()
{
    mem(miya,0);
    rep(i,1,m)
    {
        repm(j,n,1)
        {
            miya[j][i] = miya[j+1][i]+hori[j+1][i]*a[j+1][i];
            if (a[j][i]) ans += miya[j][i];
        }
    }
}

signed main()
{
    cin >> n >> m;
    rep(i,1,n)
        rep(j,1,m)
        {
            char c; cin >> c;
            a[i][j] = c=='*';
        }
    calc_r();
    calc_up();
    calc_down();
    calc_l();
    calc_up();
    calc_down();
    cout << ans << '\n';
}
