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
const int N = 210;

int dpa[N][N], dpb[N][N], a[N], sum[N], n;

signed main()
{
    cin >> n;
    rep(i,1,n)
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    n <<= 1;
    rep(i,1,n)
    {
        sum[i] = sum[i-1]+a[i];
    }
    mem(dpa,0xc0);
    mem(dpb,0x3f);
    rep(i,1,n)
    {
        dpa[i][i-1] = 0;
        dpb[i][i-1] = 0;
    }
    rep(i,1,n)
    {
        dpa[i][i] = 0;
        dpb[i][i] = 0;
    }
    rep(k,2,n)
    {
        rep(i,1,n+1-k)
        {
            int j = i+k-1;
            rep(k,i,j-1)
            {
                dpa[i][j] = max(dpa[i][j], dpa[i][k]+dpa[k+1][j]+sum[j]-sum[i-1]);
                dpb[i][j] = min(dpb[i][j], dpb[i][k]+dpb[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    n >>= 1;
    int ansa=-9e18, ansb=9e18;
    rep(i,1,n)
    {
        ansa = max(ansa, dpa[i][i+n-1]);
        ansb = min(ansb, dpb[i][i+n-1]);
    }
    cout << ansb << '\n' << ansa << '\n';
}