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

stack<int> s;

signed main()
{
    ShinraTensei
    int n;
    cin >> n;
    int ans = 0;
    rep(i,1,n+1)
    {
        int a;
        if (i == n+1)
            a = 0;
        else
            cin >> a;
        

        while (!s.empty() && s.top()>a)
            s.pop(), ans++;
        if (s.empty() || s.top()<a)
            s.push(a);
    }
    cout << ans << '\n';
}