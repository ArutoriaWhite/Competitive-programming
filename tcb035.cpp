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
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

int n, v, res, a[N];
unordered_map<int,int> mp;

signed main()
{
    ShinraTensei
    cin >> n;
    rep(i,1,n) cin >> a[i];
    cin >> v;
    rep(i,1,n)
    {
        res += mp[v-a[i]];
        mp[a[i]]++;
    }
    cout << res << '\n';
}