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

int c[N][N], t, n, a[N];

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        rep(i,1,N-1) rep(j,1,N-1) c[i][j] = i%2;
        rep(i,1,n)
        {
            rep(j,1,a[i])
            {
                c[i+1][j] = c[i][j];
            }
        }
        rep(i,1,n+1)
        {
            rep(j,1,N-1)
            {
                cout << (char)('a'+c[i][j]);
            }
            cout << '\n';
        }
    }
}