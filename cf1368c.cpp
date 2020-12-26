#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;

vector<pii> ans;

signed main()
{
    haaachamachama
    int n;
    cin >> n;
    for (int i=2,j=1; j<=n; j++,i+=2)
    {
        ans.push_back({i,1});
        ans.push_back({i,2});
        ans.push_back({i,3});
        ans.push_back({i,0});
        ans.push_back({i,4});
    }
    for (int i=1,j=1; j<=n+1; i+=2,j++)
    {
        ans.push_back({i,2});
    }
    for (int i=1,j=1; i<=n; i++,j+=2)
    {
        ans.push_back({j,(i&1? 0:4)});
        if (i==n) ans.push_back({j+2,(n&1? 4:0)});
    }
    ans.push_back({1,1});
    ans.push_back({n+1,(n&1? 3:1)});
    cout << ans.size() << '\n';
    for (auto p: ans) cout << p.ff << ' ' << p.ss << '\n';
}