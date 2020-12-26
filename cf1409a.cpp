#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    exploootion
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a==b) cout << 0 << '\n';
        else cout << ((abs(a-b)-1)/10+1) << '\n';
    }
}