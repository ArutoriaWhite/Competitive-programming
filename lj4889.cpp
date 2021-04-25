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

int n, m, h[N];
map<int,int> add, minu;

signed main()
{
    cin >> n >> m;
    rep(i,1,n) cin >> h[i];
    rep(i,1,n)
    {
        add[i+h[i]]++;
        minu[i-h[i]]++;
    }
    int res = 0;
    rep(i,1,n)
    {
        res += minu[i+h[i]];
        res += minu[i-h[i]]-1;
        res += add[i-h[i]];
        res += add[i+h[i]]-1;
    }
    cout << res/2 << '\n';
}
