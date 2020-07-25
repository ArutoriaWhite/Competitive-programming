#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

int n, m;
int r[N], used[N], d[N], s[N], t[N];

inline bool suc (int k)
{
    memset(used,0,sizeof(used));
    for (int i=1; i<=k; i++)
    {
        used[s[i]] += d[i];
        used[t[i]+1] -= d[i];
    }
    for (int i=1; i<=n; i++)
    {
        used[i] = used[i-1] + used[i];
        if (used[i] > r[i]) return 0;
    }
    return 1;
}

inline int bs()
{
    int i = 0, k = m;
    while (k > 0)
    {
        if (i+k <= m && suc(i+k))
            i += k;
        else
            k >>= 1;
    }
    return i;
}

signed main()
{
    Eriri
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> r[i];
    for (int i=1; i<=m; i++)
        cin >> d[i] >> s[i] >> t[i];
    int b = bs();
    if (b == m) cout << 0 << '\n';
    else cout << -1 << '\n' << b+1 << '\n';
}
