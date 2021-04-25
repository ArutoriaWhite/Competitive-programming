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

int to[N], x[N];
set<pii> s; // dis, start point

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> x[i];
    sort(x+1,x+1+n);
    rep(i,1,n-1)
    {
        to[i] = i+1;
        mp.insert({x[to[i]] - x[i],i});
    }
    auto dis;
    while (k--)
    {
        dis = s.begin();
        to[dis->ss]++;
        erase(dis);
        if (to[dis->ss]<=n)
            s.insert({x[to[dis->ss]]-x[dis->ss], dis->ss})
    }
    cout << dis.ff << '\n';
}