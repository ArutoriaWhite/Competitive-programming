#include <iostream>
#include <vector>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e4+10, T = 1e3+10, X = N*__lg(T);

int n, v, dp[T];
vector<int> c, w;

signed main()
{
    SakuraMyWife
    char _;
    int h1, h2, m1, m2;
    cin >> h1 >> _ >> m1 >> h2 >> _ >> m2 >> n;
    if (m1 > m2) h2--, m2+=60;
    v = (h2-h1)*60 + m2-m1;
    
    c.reserve(X);
    w.reserve(X);
    rep(i,1,n)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z==0) z = 1e8;
        z = min(z, v/x);
        for (int j=1,f=1; f; j<<=1)
        {
            int owo;
            if (z>=j) owo=j;
            else owo=z, f=0;                
            z -= owo;
            c.pb(owo*y);
            w.pb(owo*x);
        }
    }
    n = c.size();
    for (int i=1; i<=n; i++)
        for (int j=v; j>=w[i-1]; j--)
                dp[j] = max(dp[j], dp[j-w[i-1]]+c[i-1]);
    cout << dp[v] << '\n';
}   