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
const int N = 2010;

int t, n;
int a[N][N], tmp[N][N], ans[10];

void calc()
{
    rep(i,1,n)
    {
        vector<int> pos[10];
        rep(j,1,n)
            pos[a[i][j]].pb(j);
        rep(j,0,9)
        {
            if (pos[j].size()<2) continue;
            int dis = (pos[j].back()-(*pos[j].begin()));
            ans[j] = max(ans[j], dis*max(i-1, n-i));
        }
    }
}
void calc2()
{
    int r1[10]={}, r2[10]={};
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            if (!r1[a[i][j]]) r1[a[i][j]] = i;
            else r2[a[i][j]] = i;
        }
    }
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            int dis = max(i-r1[a[i][j]],r2[a[i][j]]-i);
            ans[a[i][j]] = max(ans[a[i][j]], dis*max(j-1, n-j));
        }
    }
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        mem(ans, 0);
        cin >> n;
        rep(i,1,n)
        {
            rep(j,1,n)
            {
                char c;
                cin >> c;
                tmp[i][j] = c-'0';
            }
        }
        rep(i,1,n)
            rep(j,1,n)
                a[i][j] = tmp[i][j];
        calc();
        calc2();
        rep(i,1,n)
            rep(j,1,n)
                a[i][j] = tmp[j][i];
        calc();
        calc2();
        rep(i,0,9) cout << ans[i] << ' ';
        cout << '\n';
    }
}