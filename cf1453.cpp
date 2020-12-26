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
const int N = 110;

int a[N], b[N];

signed main()
{
    int t, n, m;
    
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,1,n) cin >> a[i];
        rep(i,1,m) cin >> b[i];
        int res=0;
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                if (a[i] == b[j])
                {
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
}