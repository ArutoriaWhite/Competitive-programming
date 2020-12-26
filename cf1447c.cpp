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
const int N = 2e5+10;

vector<pii> b, s; // index, weight
int t, n, w, k;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> w;
        k = (w-1)/2+1;
        int sum=0;
        b.clear();
        s.clear();
        rep(i,1,n)
        {
            int x;
            cin >> x;
            if (x > w) continue;
            else if (x>=k) b.pb({i,x});
            else s.pb({i,x}), sum+=x;
        }
        if (b.size())
        {
            cout << 1 << '\n';
            cout << b[0].ff << '\n';
        }
        else if (sum >= k)
        {
            int m=0, owo=0;
            vector<int> ans;
            while (owo < k)
            {
                owo += s[m].ss;
                ans.pb(s[m].ff);
                m++;
            }
            cout << m << '\n';
            for (auto x: ans) cout << x << ' ';
            cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
}