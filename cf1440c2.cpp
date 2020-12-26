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
const int N = 110;

int a[N][N], n, m, t;
vector<pii> out;

int flip (int x, int y, int must=0)
{
    if (must || a[x][y]&1)
    {
        a[x][y]++;
        out.pb({x,y});
        return 1;
    }
    return 0;
}
void rem (int x, int y)
{
    int tor = (a[x][y]&1)+(a[x+1][y]&1)+(a[x][y+1]&1)+(a[x+1][y+1]&1);
    int r0, r1;
    if (!tor) return;   
    if (tor <= 2) r0 = 2, r1 = 1;
    else r0 = 0, r1 = 3;
    rep(i,0,1)
    {
        rep(j,0,1)
        {
            int r=x+i, c=y+j;
            if (r0 && !(a[r][c]&1)) flip(r,c,1), r0--;
            else if (r1 && (a[r][c]&1)) flip(r,c,1), r1--;
        }
    }
    rem(x,y);
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        out.clear();
        cin >> n >> m;
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                char c;
                cin >> c;
                a[i][j] = c=='1';
            }
        }
        if ((n&1) && (m&1) && (a[n][m]&1))
        {
            flip(n,m,1);
            flip(n-1,m,1);
            flip(n-1,m-1,1);
        }
        if (n&1)
        {
            for (int j=1; j<m; j+=2)
            {
                int cnt=0;
                cnt += flip(n,j);
                cnt += flip(n,j+1);
                if (cnt==1) flip(n-1,j,1),flip(n-1,j+1,1);
                if (cnt==2) flip(n-1,j,1);
            }
        }
        if (m&1)
        {
            for (int i=1; i<n; i+=2)
            {
                int cnt=0;
                cnt += flip(i,m);
                cnt += flip(i+1,m);
                if (cnt==1) flip(i,m-1,1),flip(i+1,m-1,1);
                if (cnt==2) flip(i,m-1,1);
            }
        }
        for (int i=1; i<n; i+=2)
            for (int j=1; j<m; j+=2)
                rem(i,j);
        cout << SZ(out)/3 << '\n';
        for (int i=0; i<SZ(out); i++)
        {
            cout << out[i].ff << ' ' << out[i].ss << ' ';
            if ((i+  1)%3==0) cout << '\n';
        }
    }
}