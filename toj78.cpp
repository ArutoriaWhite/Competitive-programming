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

int n;
pii a[N];

signed main()
{
    SakuraMyWife
    cin >> n;
    rep(i,1,n) cin >> a[i].ff >> a[i].ss;
    sort(a+1, a+1+n);

    int curl=a[1].ff, curr=a[1].ss;
    rep(i,2,n)
    {
        if (a[i].ff>curr)
        {
            cout << curl << ' ' << curr << '\n';
            curl = a[i].ff;
            curr = a[i].ss;
        }
        else    
            curr = max(curr, a[i].ss);
    }
}