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
const int N = 1e5+10;

int clen, cright, sum;
pii a[N];
int n;

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> a[i].ff >> a[i].ss;
    sort(a+1,a+1+n);
    rep(i,1,n)
    {
        int l = a[i].ff;
        int r = a[i].ss;
        if (cright < l)
        {
            sum += clen;
            clen = r-l;
            cright = r;
        }
        else
        {
            clen += max(0LL,r-cright);
            cright = max(cright, r);
        }
    }
    cout << sum+clen << '\n';
}