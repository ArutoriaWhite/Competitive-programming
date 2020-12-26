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
using namespace std;
typedef pair<int,int> pii;

int a[110][110];
int t, n;

signed main()
{
    cin >> t;
    while (t--)
    {
        memset(a,0,sizeof(a));
        cin >> n;
        rep(i,1,n) a[i][i]+=1;
        rep(i,1,n) a[i][n-i+1]=1;
        if (n&1)
        {
            int x = (n/2)+1;
            a[x][x-1]=a[x][x+1]=a[x-1][x]=a[x+1][x]=1;
        }
        rep(i,1,n)
        {
            rep(j,1,n) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
}