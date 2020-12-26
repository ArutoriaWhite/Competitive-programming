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

int a[N], n, m;
set<int> s;

signed main()
{
    cin >> m >> n;
    rep(i,1,n)
    {
        string in;
        cin >> in;
        int x = 0;
        for (int j=0; j<SZ(in); j++)
            x |= (1<<(in[j]-'A'));
        s.insert(x);
        a[i] = x;
    }
    int res=0;
    rep(i,1,n)
    {
        if (s.count( a[i]^((1<<m)-1) ))
        {
            res++;
        }
    }
    cout << res/2 << '\n';
}