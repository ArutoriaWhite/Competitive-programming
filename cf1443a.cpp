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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

int t, n;

signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,n-1,2*n)
        {
            cout << 2*i << ' ';
        }
        cout << '\n';
    }
}