#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
#define int long long
using namespace std;
typedef pair<int,int> pii;

vector<int> a;
int ans, n, c, suf[50];

void dfs (int i, int s)
{
    if (ans == c) return;
    if (i >= a.size())
    {
        ans = max(ans, s);
        return;
    }
    if (suf[i] < ans - s)
    {
        return;
    }
    if (c-s>=a[i])
        dfs(i+1,s+a[i]);
    dfs(i+1,s);
}

signed main()
{
    ShinraTensei
    cin >> n >> c;
    rep(i,1,n)
    {
        int w; cin >> w;
        if (w > c) break;
        a.pb(w);
    }
    reverse(a.begin(), a.end());
    for (int i=a.size()-1; i>=0; i--)
    {
        suf[i] = suf[i+1] + a[i];
    }
    dfs(0,0);
    cout << ans << '\n';
}