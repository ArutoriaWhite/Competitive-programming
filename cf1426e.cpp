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

signed main()
{
    SakuraMyWife
    int n;
    cin >> n;
    int a1, a2, a3;
    int b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    cout << n-min(n-b2,a1)-min(n-b3,a2)-min(n-b1,a3) << ' ';
    cout << min(a1,b2)+min(a2,b3)+min(a3,b1) << '\n';
}