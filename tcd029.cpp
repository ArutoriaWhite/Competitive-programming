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

int h[N], p[N], n;
vector<pii> st;

signed main()
{
    ShinraTensei
    cin >> n;
    rep(i,1,n) cin >> h[i];
    rep(i,1,n) cin >> p[i];
    rep(i,1,n) h[i]*=-1, p[i]*=-1;

    int ans=0;
    st.pb({-1e18, 0});
    rep(i,1,n)
    {
        pii j = *prev(upper_bound(st.begin(), st.end(), pii{h[i]+p[i],0}));
        ans += st.back().ss - j.ss;
        int w = st.back().ss+1;
        while (st.back().ff >= h[i])
            st.pop_back();
        st.pb({h[i], w});
    }

    cout << ans << '\n';
}