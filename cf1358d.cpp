#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e5;

int a[N], pcnt[N], pval[N], n, k, ans;

signed main()
{
    Eriri
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i], a[i+n] = a[i]; 
    for (int i=1; i<=n; i++)
    {
        pcnt[i] = a[i]+pcnt[i-1];
        pval[i] = a[i]*(a[i]+1)/2 + pval[i-1];
    }
    for (int i=1; i<=n; i++)
    {
        pcnt[i+n] = a[i] + pcnt[i+n-1];
        pval[i+n] = a[i]*(a[i]+1)/2 + pval[i+n-1];
    }
    for (int i=1; i<=2*n; i++)
    {
        int p = lower_bound(pcnt+1,pcnt+i+1,pcnt[i]-k) - pcnt;
        if (p == 2*n+1) continue;
        if (pcnt[i] < k) continue;
        int res = pval[i]-pval[p];
        int hd = a[p], tl = a[p]-(k-(pcnt[i]-pcnt[p]))+1;
        int x = (hd+tl)*(hd-tl+1)/2;
        res += x;
        ans = max(ans, res);
    }
    cout << ans << '\n';
}