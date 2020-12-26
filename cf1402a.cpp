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
const int N = 1e5+10, M = 1e9+7;

vector<pii> st; //h, w
int sum, res, n, inv2;
int hh[N], ww[N];

int qpow (int i, int j)
{
    int res = 1;
    for(; j; j>>=1,i=i*i%M)
        if (j&1)
            res = res*i%M;
    return res;
}
int calc (int i){ return (i+1)*i%M*inv2%M; }

signed main()
{
    inv2 = qpow(2,M-2);
    cin >> n;
    rep(i,1,n) cin >> hh[i];
    rep(i,1,n) cin >> ww[i];
    rep(i,1,n)
    {
        int h = hh[i], w = ww[i], nw = ww[i];
        while (!st.empty() && st.back().ff>h)
        {
            nw = (nw+st.back().ss)%M; 
            sum = (sum-st.back().ss*calc(st.back().ff)%M+M)%M;
            st.pop_back();
        }
        res = (res + calc(w)*calc(h)%M)%M;
        res = (res + (nw-w+M)*w%M*calc(h)%M)%M;
        res = (res + w*sum%M)%M;
        sum = (sum + nw*calc(h)%M)%M;
        st.pb({h,nw});
    }
    cout << res << '\n';
}