#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int pa[N], pb[N], n, d, m, ans;
vector<int> a, b;

signed main()
{
    XinAi
    cin >> n >> d >> m;
    for (int i=0,x; i<n; i++)
    {
        cin >> x;
        if (x <= m) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end(), [](int i, int j){return i>j;});
    sort(b.begin(), b.end(), [](int i, int j){return i>j;});
    for (int i=1; i<=a.size(); i++) pa[i] = pa[i-1] + a[i-1];
    for (int i=1; i<=b.size(); i++) pb[i] = pb[i-1] + b[i-1];
    for (int i=0; i<=a.size(); i++)
        ans = max(ans, pa[i] + pb[((n-i-1)/(d+1)+1)]);
    cout << ans << '\n';
}