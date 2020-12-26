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
const int N = 100;

int a[N], b[N], n, k, t;

int check()
{
    rep(i,1,n)
        if (a[i]+b[n-i+1] > k) return 0;
    return 1;
}

signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        rep(i,1,n) cin >> a[i];
        rep(i,1,n) cin >> b[i];
        cout << (check()? "Yes":"No") << '\n';
    }
}