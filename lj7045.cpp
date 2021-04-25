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
const int N = 5e4+10;

int ans[N], n, T, q;

/*
enum 2..n-1 as i
    if (same(i-1,i))
        swap(ans[i], ans[i+1])
if (same(n-2,n-1))
    swap(ans[n-2],ans[n-1])
*/
int same (int x, int y)
{
    cout << x << ' ' << y << endl;
    int ret;
    cin >> ret;
    return ret;
}
signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> q;
        if (n <= 2)
        {
            if (same(0,1))
            {
                cout << -1 << endl;
            }
            else
            {
                cout << n << endl;
                cout << 0 << ' ' << 1 << endl;
            }
        }
        else
        {
            rep(i,0,n-1)
                ans[i] = i;
            rep(i,1,n-2)
            {
                if (same(ans[i-1], ans[i]))
                    swap(ans[i], ans[i+1]);
            }
            if (same(ans[n-2], ans[n-1]))
                swap(ans[n-3], ans[n-2]);

            cout << n << endl;
            rep(i,0,n-1)
                cout << ans[i] << ' ';
            cout << endl;
        }
    }
}