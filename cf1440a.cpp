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

int n, c0, c1, h;
string s;
int t;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> c0 >> c1 >> h >> s;
        int a0, a1;
        a0 = min(c0, c1+h);
        a1 = min(c1, c0+h);
        int res=0;
        for (int i=0; i<SZ(s); i++)
        {
            res += (s[i]=='0'? a0:a1);
        }
        cout << res << '\n';
    }
}