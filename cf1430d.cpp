#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int t, n, cnt[N];
char c[N];

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> n;
        rep(i,1,n) cin >> c[i];

        int k=0;
        char lastC = 0;
        rep(i,1,n)
        {
            if (c[i]!=lastC)
            {
                lastC = c[i];
                k++;
            }
            cnt[k]++;
        }
        int j=1, ans=0;
        rep(i,1,k)
        {
            while (j<=n&&cnt[j]<2) j++;
            if (j>n)
            {
                ans += (k-i)/2+1;
                break;
            }
            else
            {
                ans++;
                cnt[i]=0;
                cnt[j]--;
            }
        }
        cout << ans << '\n';
    }
}