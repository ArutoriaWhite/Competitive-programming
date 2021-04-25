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

int n, ans;
stack<int> st;

signed main()
{
    ShinraTensei
    cin >> n;
    rep(i,1,n)
    {
        int d, h;
        cin >> d >> h;

        while (!st.empty() && st.top() > h)
            st.pop(), ans++;
        if (st.empty() || st.top() != h)
            st.push(h);
    }
    cout << ans + st.size() << '\n';
}