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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

int cnt[N], n, k;

signed main()
{
    SakuraMyWife
    cin >> n >> k;
    for (int i=0,a,b; i<n; i++)
    {
        cin >> a >> b;
        cnt[a] += b;
    }
    int res=0, flag=0;
    for (int i=0; i+k<N; i++)
    {
        if (!cnt[i]) continue;
        if (k>0)
        {
            int x = min(cnt[i], cnt[i+k]);
            if (x>0) flag=1;
            res = max(res, x*(2*i+k));
        }
        else if (cnt[i] >= 2)
        {
            flag=1;
            res = max(res, cnt[i]*i);
        }

    }
    if (flag) cout << res << '\n';
    else cout << "NO\n";
}