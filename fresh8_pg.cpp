#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

int mcnt, mdp, n, c, a[N], cnt, dp;

signed main()
{
    Eriri
    cin >> n >> c;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    mdp = -a[1];
    for (int i=1; i<=n; i++)
    {
        if (mdp + a[i] - c > dp)
        {
            dp = mdp + a[i] - c;
            cnt = mcnt + 1;
        }
        if (dp-a[i+1] > mdp)
        {
            mcnt = cnt;
            mdp = dp-a[i+1];
        }
    }
    cout << dp << ' ' << cnt << '\n';
}