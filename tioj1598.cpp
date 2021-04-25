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

const int N = 1e5+10;

int n, m, a[N];

inline int can (int t)
{
    priority_queue<int,vector<int>,less<int>> pq;
    rep( i,1,n) pq.push(a[i]);
    rep(i,1,m)
    {
        if (pq.top() <= t) return 1;
        if (pq.top() <= 3) return 0;    
        int x = pq.top();
        pq.pop();
        pq.push((x/2)+(x&1));
        pq.push((x/2));
    }
    return pq.top() <= t;
}
int bs()
{
    int i = 0, s = 1e6+10;
    while (s > 0)
    {
        if (can(i+s)) s >>= 1;
        else i += s;
    }
    return i+1;
}

signed main()
{
    ShinraTensei
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    cout << bs() << '\n';
}