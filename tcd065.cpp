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
const int N = 1e5+10;

int n;
stack<pii> st; // h, w

signed main()
{
    ShinraTensei
    cin >> n;

    int res = 0;
    rep(i,1,n+1)
    {
        int h; cin >> h;
        if (i == n+1) h = 0;
        int w = 0;
        while (!st.empty() && st.top().ff >= h)
        {
            w += st.top().ss;
            res = max(res, st.top().ff*w);
            st.pop();
        }
        st.push({h,w+1});
        
    }
    cout << res << '\n';
}