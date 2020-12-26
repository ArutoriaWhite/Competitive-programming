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

int a[N], n, t, cnt[N];

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin >> n;
        rep(i,1,n) cin >> a[i];
        a[1] = 1e9, cnt[0] = 1;
        
        int cur=0;
        rep(i,2,n)
        {
            if (a[i]<a[i-1])
            {
                if (cnt[cur] <= 0) cur++;
                cnt[cur]--;
            }
            cnt[cur+1]++;
        }
        cout << cur+1 << '\n';
    }
}