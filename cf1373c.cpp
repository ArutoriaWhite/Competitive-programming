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
const int N = 1e6+10;

int a[N], lim[N], pre[N], t, n;

int bs (int cur)
{
    int i=1, s=n;
    while (s>0)
    {
        if (i+s>n || lim[i+s]>cur) s>>=1;
        else i += s;
    }
    return i;
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        n = s.size();
        rep(i,1,n) a[i] = (s[i-1]=='+'? 1:-1);
        rep(i,1,n) pre[i] = a[i]+pre[i-1];
        rep(i,1,n) lim[i] = max(lim[i-1], -pre[i-1]);
        int res = 0;
        rep(i,0,n) 
        {
            int len = bs(i);
            res += len;
            if (i >= lim[n] && i>=-pre[n]) break;
        }
        cout << res << '\n';
    }
}