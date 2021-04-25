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
const int N = 30;

int n, p, a[N], ans;

void dfs (int i, int sum)
{
    if (sum > p) return;
    ans = max(ans, sum);
    if (i > n) return;
    dfs(i+1,sum+a[i]);
    dfs(i+1,sum);
}

signed main()
{
    cin >> n >> p;
    rep(i,1,n) cin >> a[i];
    dfs(1,0);
    cout << ans << '\n';
}