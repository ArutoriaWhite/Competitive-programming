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

int n, k, a[N], t;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n*k) cin >> a[i];
        int m = n/2;
        int res=0;
        for (int i=n*k-m,j=0; j<k; i-=m+1,j++)
        {
            res += a[i];
        }
        cout << res << '\n';
    }
}