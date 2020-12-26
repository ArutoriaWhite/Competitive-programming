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
const int N = 1e6+10;

pii a[N<<1];
int n;

signed main()
{
    ShinraTensei
    while (cin >> n)
    {
        rep(i,1,n)
        {
            cin >> a[i].ff >> a[i+n].ff;
            a[i].ss = 1;
            a[i+n].ss = 0;
            a[i+n].ff++;
        }
        int cur=0, ans=0;
        sort(a+1, a+1+2*n);
        rep(i,1,2*n)
        {
            if (a[i].ss == 1)
            {
                cur++;
            }
            else
            {
                cur--;
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
}