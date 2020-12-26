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

signed main()
{
    ShinraTensei
    int n, m;
    while (cin >> n >> m, (n||m))
    {
        string tot=" ", s;
        rep(i,1,n)
        {
            cin >> s;
            tot += s;
        }
        rep(i,1,m)
        {
            int x;
            cin >> x;
            cout << tot[x];
        }
        cout << '\n';
    }
}