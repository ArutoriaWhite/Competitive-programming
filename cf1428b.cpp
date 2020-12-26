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

string s;
int t, n;

int all_ueq (char c)
{
    for (int i=0; i<n; i++)
        if (s[i] == c)
            return 0;
    return 1;
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        if (all_ueq('>') || all_ueq('<'))
        {
            cout << n << '\n';
        }
        else
        {
            int ans=0;
            for (int i=0; i<n; i++)
            {
                if (s[i]=='-' || s[(i+1)%n]=='-')
                    ans++;
            }
            cout << ans << '\n';
        }
    }
}