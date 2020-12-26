#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int unsigned long long 
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

bitset<70> ani, vis;
int n, m, c, k;

signed main()
{
    cin >> n >> m >> c >> k;
    if (n==0 && m==0 && k==64)
    {
        cout << "18446744073709551616\n";
        return 0;
    }
    for (int i=0,x; i<n; i++)
    {
        cin >> x;
        ani |= x;
    }
    for (int i=0,p,q; i<m; i++)
    {
        cin >> p >> q;
        vis[p] = 1;
    }
    int cnt = (vis&ani.flip()).count();
    int ans = ((__int128)1<<(k-cnt))-n;
    cout << ans << '\n';
}