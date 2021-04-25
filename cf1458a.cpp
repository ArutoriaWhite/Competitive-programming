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
const int N = 2e5+10;

int n, m, a[N];
int g;

signed main()
{
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];

    sort(a+1,a+1+n,[](int i, int j){return i>j;});
    rep(i,1,n-1)
        g = __gcd(g,a[i]-a[i+1]);

    rep(i,1,m)
    {
        int b; cin >> b;
        cout << __gcd(a[1]+b, g) << ' ';
    }
    cout << '\n';
}