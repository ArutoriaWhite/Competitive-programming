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
const int N = 110;

int a[N], n, t, m;

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int x, sum=0;
        rep(i,1,n) cin >> x, sum += x;
        cout << (sum==m? "YES":"NO") << '\n';
    }
}