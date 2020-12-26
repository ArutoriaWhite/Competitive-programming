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
const int N = 1010;

int a[N], b[N], c[N];
int t, n;

signed main()
{
    SakuraMyWife
    memset(a,-1,sizeof(a));
    for (int i=1; i<N; i++)
    {
        int flag=1;
        for (int j=0; j*3<=i&&flag; j++)
        {
            for (int k=0; k*5+j*2<=i&&flag; k++)
            {
                if ((i-j*3-k*5)%7==0)
                {
                    a[i]=j,b[i]=k,c[i]=(i-j*3-k*5)/7;
                    flag=0;
                }
            }
        }
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (a[n]<0) cout << -1 << '\n';
        else cout << a[n] << ' ' << b[n] << ' ' << c[n] << '\n';
    }
}