#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define repm(i,j,k) for (int i=j; i>=k; i--)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 30;

char C[N][N];
int n, m;
unordered_set<string> s;

int rotate (int x, int y, int h, int w)
{
    string str[5];
    rep(i,1,h)
    {
        rep(j,1,w) str[1] += C[i+x-1][j+y-1];
        str[1] += '\n';
    }
    repm(i,h,1)
    {
        repm(j,w,1) str[2] += C[i+x-1][j+y-1];
        str[2] += '\n';
    }
    rep(j,1,w)
    {
        repm(i,h,1) str[3] += C[i+x-1][j+y-1];
        str[3] += '\n';
    }
    repm(j,w,1)
    {
        rep(i,1,h) str[4] += C[i+x-1][j+y-1];
        str[4] += '\n';
    }
    rep(i,1,4)
        if (s.find(str[i]) != s.end()) return 1;
    s.insert(str[1]);
    return 0;
}

int legal (int h, int w)
{
    if (n%h || m%w) return 0;
    s.clear();
    for (int i=1; i<=n; i+=h)
        for (int j=1; j<=m; j+=w)
            if (rotate(i,j,h,w)) return 0;
    return 1;
}

signed main()
{
    cin >> n >> m;
    rep(i,1,n)
        rep(j,1,m)
            cin >> C[i][j];

    vector<pii> ans;
    rep(h,1,n)
        rep(w,1,m)
            if (legal(h,w))
                ans.pb({h,w});

    pii anspair = {1000,1000};
    for (auto pr: ans)
        if (pr.ff*pr.ss < anspair.ff*anspair.ss)
            anspair = pr;
    cout << ans.size() << '\n' << anspair.ff << ' ' << anspair.ss << '\n';
}