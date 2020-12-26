#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 310;

int t, k, n, a[N][N];

void fillwith (int x, int y, int &k)
{
    if (k<=0) return;
    for (; x<=n&&y<=n&&k>0; x++,y++)
        a[x][y] = 1, k--;
}
int calc()
{
    int Mr=0, mr=1e9;
    rep(y,1,n)
    {
        int sum=0;
        rep(x,1,n) sum += a[x][y];
        Mr = max(Mr, sum);
        mr = min(mr, sum);
    }
    int Mc=0, mc=1e9;
    rep(x,1,n)
    {
        int sum=0;
        rep(y,1,n) sum += a[x][y];
        Mc = max(Mc, sum);
        mc = min(mc, sum);
    }
    return (Mr-mr)*(Mr-mr) + (Mc-mc)*(Mc-mc);
}

signed main()
{
    exploootion
    cin >> t;
    while (t--)
    {
        memset(a,0,sizeof(a));
        cin >> n >> k;
        rep(i,1,n)
        {
            if (i==1)
                fillwith(1,1,k);
            else
            {
                fillwith(i,1,k);
                fillwith(1,n-i+2,k);
                fillwith(1,i,k);
                fillwith(n-i+2,1,k);                
            }
        }
        cout << calc() << '\n';
        rep(y,1,n)
        {
            rep(x,1,n) cout << a[x][y];
            cout << '\n';
        }
    }
}