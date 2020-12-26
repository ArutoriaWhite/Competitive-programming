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
const int N = 2e5+10;

int a[N], b[N], t, n;

inline int legal (int k)
{
    int owo=0;
    rep(i,1,n)
        if (a[i]>k) owo+=b[i];
    return owo<=k;
}

inline int bs()
{
    int i=0, s=2e9;
    while (s>0)
    {
        if (legal(i+s)) s>>=1;
        else i += s;
    }
    return i+1;
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) cin >> b[i];
        cout << bs() << '\n';
    }
}