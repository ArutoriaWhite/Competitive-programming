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
const int N = 1e5+10;

int a, b, n, t;
string s;

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> s;
        int res=0, len=0, flag=0;
        for (int i=0; i<SZ(s); i++)
        {
            if (s[i]=='1')
            {
                if (!flag) res += a;
                else if (s[i-1]=='0')
                    res += min(a, len*b);
                len = 0;
                flag=1;
            }
            else
            {
                len++;
            }
        }
        cout << res << '\n';
    }
}