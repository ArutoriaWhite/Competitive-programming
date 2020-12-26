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

vector<int> G[N];
int n, sum[N], leaf[N];

void dfs (int u)
{
    leaf[u] = G[u].size()==0;
    for (auto v: G[u])
    {
        dfs(v);
        sum[u] += sum[v];
        leaf[u] += leaf[v];
    }
}

signed main()
{
    SakuraMyWife
    cin >> n;
    rep(i,2,n)
    {
        int p; cin >> p;
        G[p].push_back(i);
    }
    rep(i,1,n) cin >> sum[i];
    dfs(1);

    int mx=0;
    rep(i,1,n)
        mx = max(mx, (sum[i]/leaf[i]+(sum[i]%leaf[i]>0)));
    cout << mx << '\n';
}