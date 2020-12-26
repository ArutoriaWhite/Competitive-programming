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
const int N = 2e5+10;

int t, n;
string s;

signed main()
{
    SakuraMyWife
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.size();
        int ans=0, cntb=0;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i]=='B') cntb++;
            else
            {
                if (cntb > 0) cntb--;
                else ans++;
            }
        }
        ans += cntb&1;
        cout << ans << '\n';
    }
}
