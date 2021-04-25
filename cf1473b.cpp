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

string a, b, x, y;

signed main()
{
    ShinraTensei
    int q;
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        x = a;
        y = b;
        while (x!=y && x.size()<=SZ(a)*SZ(b))
        {
            if (x.size() < y.size())
            {
                x += a;
            }
            else 
            {
                y += b;
            }
        }
        cout << (x==y? x:"-1") << '\n';
    }
}