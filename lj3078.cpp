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
const int N = 1e5+10;

int a, b, ans, n;

signed main()
{
    ShinraTensei
    cin >> n;
    while (n--)
    {
        cin >> a;
        ans += max(0LL, a-b);
        b = a;
    }
    cout << ans << '\n';
}