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

int x[N], y[N], n, t, k;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) cin >> x[i] >> y[i];
        int flag=-1;
        rep(i,1,n)
        {
            int cnt=0;
            rep(j,1,n)
            {
                if (abs(x[i]-x[j])+abs(y[i]-y[j]) <= k)
                {
                    cnt++;
                }
            }
            if (cnt == n)
            {
                flag=1;
            }
        }
        cout << flag << '\n';
    }
}