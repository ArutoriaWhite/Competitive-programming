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
const int N = 5e5+10;

int a[N], n;

signed main()
{
    cin >> n;
    rep(i,1,n) cin >> a[i];
    int sum=0;
    rep(i,1,n)
    {
        sum ^= a[i];
    }
    if (sum==0)
    {
        cout << "lose\n";
    }
    else
    {

        int res;
        for (int t=1; t<=sum; t<<=1)
        {
            res = t;
        }
        rep(i,1,n)
        {
            if (a[i]&res)
            {
                int ori = a[i];
                for (int t=1; t<=sum; t<<=1)
                {
                    if (t&sum)
                    {
                        a[i] ^= t;
                    }
                }
                cout << ori-a[i] << ' ' << i << '\n';
                rep(i,1,n) cout << a[i] << ' ';
                cout << '\n';
                break;
            }
        }
    }
}