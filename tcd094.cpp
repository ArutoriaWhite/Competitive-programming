#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e6+10;

int a[N], n, ed, l, r;
queue<int> q;
int dep[N];

int legal (int i) // unvisited, legal, 
{
    if (i<0 || i>n || a[i]<0 || a[i]>n || dep[a[i]]>=0) return 0;
    return 1;
}

int bfs()
{
    q.push(0);
    mem(dep,-1);
    dep[0] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        if (u == ed) return dep[u];
        if (legal(u-l))
        {
            dep[a[u-l]] = dep[u]+1;
            q.push(a[u-l]);
        }
        if (legal(u+r))
        {
            dep[a[u+r]] = dep[u]+1;
            q.push(a[u+r]);
        }        
    }
    return -1;
}

signed main()
{
    ShinraTensei
    cin >> n >> ed >> l >> r;
    rep(i,0,n-1) cin >> a[i];
    cout << bfs() << '\n';
}