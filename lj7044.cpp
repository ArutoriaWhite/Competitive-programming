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
const int N = 20;

int cnt[N][N];

void calc (int l, int r, int k)
{
    if (k==0) cnt[l][r]++;
    else
    {
        for (int i=l; i<r; i++)
        {
            for (int j=l+1; j<=r; j++)
            {
                calc(i,j,k-1);
            }
        }
    }
}

signed main()
{
    int n, k;
    cin >> n >> k;
    calc(0,n,k);
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j+i<=n; j++)
        {
            de(j), de(j+i), de(cnt[j][j+i]), dd;
        }
        dd;
    }
}