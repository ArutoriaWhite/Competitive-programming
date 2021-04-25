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
/*
giving n(2e5), m(100), k(n), and a[N](n)
answer how mucn sets consist of m element max-min <= k
*/
const int N = 2e5+10, D = 1e9+7;
int a[N], n, m, k, t;
int csum[N], inv[N], fac[N];

int qpow (int i, int j)
{
    int res = 1;
    for (; j; j>>=1,i=i*i%D)
        if (j&1)
            res = res*i%D;
    return res;
}
void buildfac()
{
    fac[0] = 1;
    rep(i,1,N-1)
        fac[i] = fac[i-1]*i%D;
    rep(i,0,N-1)
        inv[i] = qpow(fac[i],D-2);
}
int C (int i, int j)
{
    return fac[i] * inv[i-j]%D * inv[j]%D;
}
void build ()
{
    rep(i,0,n)
        csum[i] = C(i,m-2);
    rep(i,1,n)
        csum[i] = (csum[i-1]+csum[i])%D;
}
int bs (int i, int j)
{
    int s = n;
    while (s > 0)
    {
        if (j+s>n || a[j+s]-a[i]>k)
            s >>= 1;
        else
            j += s;
    }
    return j;
}

signed main()
{
    ShinraTensei
    cin >> t;
    buildfac();
    while (t--)
    {
        cin >> n >> m >> k;

        rep(i,1,n) cin >> a[i];
        sort(a+1,a+1+n);

        if (m == 1)
        {
            cout << n << '\n';
            continue;
        }

        build();
        int ans = 0;
        rep(i,1,n)
        {
            int j1 = i+m-1;
            if (j1>n || a[j1] - a[i] > k) continue;
            int j2 = bs(i,j1);
            if (j1-i-1 == 0)
                ans = (ans + csum[j2-i-1])%D;
            else 
                ans = (ans + csum[j2-i-1] - csum[j1-i-2]+D)%D;
        }
        cout << ans << '\n';
    }
}
/*
4
4 3 2
1 2 4 3
4 2 1
1 1 1 1
1 1 1
1
10 4 3
5 6 1 3 2 9 8 1 2 4

1
4 3 2
1 2 3 4

1
4 2 1
1 1 1 1

1
1 1 1
1
*/