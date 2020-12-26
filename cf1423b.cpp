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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e4+10;

vector<pii> G[N]; //w, to

int xyl (int k)
{
    int res=0;
    rep(i,1,n)
    {
        mem(vis,0);
        if ()
    }
}
int bs()
{
    int i=0, s=2e9;
    while (s>0)
    {
        if (xyl(i+s)==n) s>>=1;
        else i += s;
    }
    return i+1;
}

signed main()
{
    cin >> n >> m;
    for (int i=0,u,v,d; i<m; i++)
    {
        cin >> u >> v >> d;
        G[u].pb({d,v});
    }
    cout << bs() << '\n'
}