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

set<int> s;
map<int,int> cnt;
int n, m, a[N];

signed main()
{
    ShinraTensei
    cin >> m >> n;
    int res=0;
    rep(i,1,n)
    {
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
        if (i-m>0)
        {
            cnt[a[i-m]]--;
            if (cnt[a[i-m]]==0)
                s.erase(a[i-m]);
        }
        if (s.size()==m) res++;
    }
    cout << res << '\n';
}