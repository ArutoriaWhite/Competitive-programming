#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int a[N], b[N], c[N], d[N];
int t, n, m;
/*
a b
c d
*/

signed main()
{
    haaachamachama
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,1,n) cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (m&1) cout << "NO\n";
        else 
        {
            int flag=0;
            rep(i,1,n) if (b[i]==c[i]) flag=1;
            cout << (flag? "YES":"NO") << '\n';
        }
    }
}