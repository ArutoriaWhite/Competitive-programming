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

int T;

int calc (int n, int x)
{
    if (2*x%n) return -1;
    int a = 2*x/n;
    if ((a-n+1)&1) return -1;
    return (a-n+1)/2;
}

signed main()
{
    ShinraTensei
    cin >> T;
    while (T--)
    {
        int x;
        cin >> x;
        int res = -1;
        rep(i,2,sqrt(x)+5)
        {
            res = calc(i,x);
            if (res>0)
                break;
        }
        if (res > 0)
        {
            cout << x << " = ";
            while (x>0)
            {
                cout << res;
                x -= res;
                res++;
                if (x>0) cout << " + ";
            }
            cout << '\n';
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}