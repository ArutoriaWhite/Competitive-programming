#include <bits/stdc++.h>

#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

int st[30][N], k, len, n, m;

inline void build()
{
    for (int i=0; i<n; i++) cin >> st[0][i];
    for (int j=1; j<=k; j++)
        for (int i=0; i+(1<<j)<=n; i++)
            st[j][i] = max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
}

int main()
{
    Eriri
    cin >> n >> m;
    k = __lg(n)+1;
    build();
    for (int i=0,l,r; i<m; i++)
    {
        cin >> l >> r, l--;
        len = __lg(r-l);
        cout << max(st[len][l],st[len][r-(1<<len)]) << '\n';
    }
}