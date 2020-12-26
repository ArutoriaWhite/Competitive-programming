#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e7;

int np[N], cnt[N];

inline int qpow (int x, int y)
{
    int res=1;
    for (; y; y>>=1,x*=x)
        if (y&1) res *= x;
    return res;
}

signed main()
{
    int n;
    cin >> n;
    np[0] = np[1] = 1;
    rep(i,2,n)
        if (!np[i])
            for (int j=i*i; j<N; j+=i) np[j]=1;
    int mx=0, mul=0, t=n, res=1;
    rep(i,2,n)
        while (!(t%i)) t/=i,cnt[i]++;
    rep(i,2,n) mx=max(mx,cnt[i]);
    if (mx==1) cout << n << ' ' << 0 << '\n';
    else
    {
        mx = qpow(2,__lg(mx-1)+1);
        rep(i,2,n) if (cnt[i]) mul |= cnt[i]!=mx;
        rep(i,2,n) if(cnt[i]) res *= i;
        cout << res << ' ' << __lg(mx)+mul << '\n';
    }
}