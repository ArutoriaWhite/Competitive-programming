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
const int N = 1e5+10, M = 1e6+10;

int n, m, p;
int cnt[M], last[M];
vector<int> ans;

signed main()
{
    SakuraMyWife
    cin >> n >> m >> p;
    rep(i,1,n)
    {
        int k;
        cin >> k;
        rep(j,1,k)
        {
            int x;
            cin >> x;
            if (last[x]!=i)
            {
                cnt[x]++;
                last[x] = i;
            }
        }
    }
    rep(i,1,m)
    {
        if (cnt[i] == p)
        {
            ans.pb(i);
        }
    }
    cout << SZ(ans) << '\n';
    for (auto x: ans) cout << x << ' ';
    cout << '\n';
}