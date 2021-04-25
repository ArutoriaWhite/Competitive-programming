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
const int N = 2e5+10;


signed main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1) cout << 9 << '\n';
        else
        {
            cout << 9 << 8;
            for (int i=0,j=9; i<n-2; i++,j=(j+1)%10)
            {
                cout << j;
            }
            cout << '\n';
        }
    }
}