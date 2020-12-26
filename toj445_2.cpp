#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std; 
typedef pair<int,int> pii;

int ans = 1e9;
int n;
inline int kaguya (int l, int r)
{
    int res = (1<<15)-1;
    res >>= 15 - (r-l+1);
    return res << l;
}
void dfs (int l, int c, int g)
{
    if (c > ans) return;
    if (g == 0){ ans = c; return; }
    if (l > n) return;
    dfs(l+1, c, g);
    for (int i=0; i+l<=n; i++)
        dfs(l+1, c+l, g^kaguya(i, i+l-1));
}

signed main()
{
    XinAi
    string s;
    cin >> s;
    n = s.size();
    int rt=0;
    for (int i=n-1; i>=0; i--) rt |= ((s[i]=='1')<<i);
    dfs(1, 0, rt);
    cout << ans << '\n';
}