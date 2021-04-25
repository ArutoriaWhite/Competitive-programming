#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

int n, m, ansh, answ;

inline int CEIL (int i, int j)
{
    if (i%j == 0) return i/j;
    return i/j+1;
}
inline void update (int i, int j)
{
    if (i*j > ansh*answ)
        ansh = i, answ = j;
    else if (i*j == ansh*answ)
        if (i > ansh)
            ansh = i, answ = j;
}

signed main()
{
    cin >> n >> m;
    
    for (int a=1; a<=n; a*=2)
    {
        int l = CEIL(a*4,5);
        int r = min(a*5/4,m);
        if (l>r) continue;
        update(a,r);
    }
    for (int b=1; b<=m; b*=2)
    {
        int l = CEIL(4*b,5);
        int r = min(5*b/4,n);
        if (l>r) continue;
        update(r,b);
    }
    cout << ansh << ' ' << answ << '\n';
}