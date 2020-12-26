#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 50, ee=0, ww=1, nn=2, ss=3;

int n, m;
int a[N][N], rx, ry, rf, tx, ty;

signed main()
{
    cin >> my >> mx;
    rep(y,1,my)
    {
        rep(x,1,mx)
        {
            char c;
            cin >> c;
            if (c=='E') rf=ee;
            if (c=='W') rf=ww;
            if (c=='N') rf=nn;
            if (c=='S') rf=ss;
            if (c=='E'||c=='W'||c=='N'|)
        }
    }
}