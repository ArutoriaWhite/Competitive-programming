#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define Exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 110;

int a[N][N], mx, my, t;

int calc (int x, int y, int z, int w)
{
    int owo[]={x,y,z,w};
    sort(owo,owo+4);
    return abs(x-owo[1])+abs(y-owo[1])+abs(z-owo[1])+abs(w-owo[1]);
}

signed main()
{
    Exploootion
    cin >> t;
    while (t--)
    {
        cin >> my >> mx;
        rep(y,1,my) rep(x,1,mx) cin >> a[y][x];
        int ans=0;
        for (int ab=1,ud=my; ab<ud; ab++,ud--)
        {
            for (int l=1,r=mx; l<r; l++,r--)
            {
                ans += calc(a[ab][l],a[ab][r],a[ud][l],a[ud][r]);
            } 
        }
        if (my&1)
        {
            for (int i=1,j=mx; i<j; i++,j--)
            {
                ans += abs(a[my/2+1][i]-a[my/2+1][j]);
            }
        }
        if (mx&1)
        {
            for (int i=1,j=my; i<j; i++,j--)
            {
                ans += abs(a[i][mx/2+1]-a[j][mx/2+1]);
            }
        }
        cout << ans << '\n';
    }
}