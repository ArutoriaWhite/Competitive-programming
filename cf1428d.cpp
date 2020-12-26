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
const int N = 1e5+10;

set<int> pos[5];
vector<pii> ans;
int a[N], vis[N], k=1, illegal;

void sol (int i)
{
    if (vis[i] || illegal) return;
    vis[i] = 1;
    pos[a[i]].erase(i);
    if (a[i] == 1)
    {
        ans.pb({k,i});
        k++;
    }
    if (a[i] == 2)
    {
        if (pos[1].upper_bound(i)==pos[1].end())
        {
            illegal=1;
            return;
        }
        int partn = *pos[1].upper_bound(i);
        ans.pb({k,i});
        sol(partn);
    }
    if (a[i] == 3)
    {
        int find=0;
        for (int j=3; j>0; j--)
        {
            if (pos[j].upper_bound(i)!=pos[j].end())
            {
                int partn = *pos[j].upper_bound(i);
                ans.pb({k,i});
                ans.pb({k,partn});
                k++;
                sol(partn);
                find=1;
                break;
            }
        }
        if (!find)
        {
            illegal = 1;
            return;
        }
    }
}

signed main()
{
    SakuraMyWife
    int n;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) pos[a[i]].insert(i);
    rep(i,1,n) sol(i);
    if (illegal) cout << -1 << '\n';
    else
    {
        cout << ans.size() << '\n';
        for (auto i: ans)
            cout << i.ff << ' ' << i.ss << '\n';
    }
}