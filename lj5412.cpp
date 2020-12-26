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
const int N = 210;


signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> typ(n+10);
        vector<string> a[2];
        rep(i,1,n) cin >> typ[i];
        rep(i,1,n)
        {
            string s;
            cin >> s;
            a[typ[i]].pb(s);
        }
        rep(i,0,1)
        {
            sort(a[i].begin(), a[i].end());
            for (auto x: a[i])
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}