#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define QQai ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

Pii p[N], rk[N];
vector<Pii> v;
int lb[N];

namespace seg
{
    int st[N<<1];
    void modify (int p, int x)
    {

    }
    int query (int l, int r)
    {
        
    }
}

inline void lisan()
{
    sort(p.begin(), p.end());
    for (int i=0; i<n; i++)
        v.push_back(p[i].F), v.push_back(p[i].S);
    v.resize(unique(v.begin(), v.end()));
    for (int i=0; i<n; i++)
    {
        rk[i].F = lower_bound(v.begin(), v.end(), p[i].F);
        rk[i].S = lower_bound(v.begin(), v.end(), p[i].S);
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> p[i].F >> p[i].S;
        lisan();
        vector<Pii> prev;
        for (int i=n-1; i>=0; i--)
        {
            if (lb[rk[i].F] == -1)
            {
                for (auto x: prev)
                    seg::modify(rk[i].S, rk[i].F);
                lb[rk[i].F] = lower_bound(rk.begin(), rk.end(), rk[i].F, cmp) - rk.begin();
            }
            for (int j=i-1; j>=lb[rk[i].F]; j--)
            {
                int res = abs(p[i].S - p[j].S) + abs(p[i].F - v[seg::query(rk[j].S, rk[i].S)]);
                ans = max(ans, res);
            }
            cout << res << '\n';
        }
    }
}