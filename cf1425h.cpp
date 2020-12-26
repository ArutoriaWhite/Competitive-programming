#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    haaachamachama
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int neg=a+b, xiao=b+c, zheng=a+d;
        if (neg&1 && zheng) cout << "Ya ";
        else cout << "Tidak ";
        if (neg&1 && xiao) cout << "Ya ";
        else cout << "Tidak ";
        if (!(neg&1) && xiao) cout << "Ya ";
        else cout << "Tidak ";
        if (!(neg&1) && zheng) cout << "Ya\n";
        else cout << "Tidak\n";
    }
}