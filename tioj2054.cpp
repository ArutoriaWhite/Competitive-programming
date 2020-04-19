#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << (x) << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e5+10;

int yord[N], n, w, l, sum, res;
set<Pii> pos; //x,y
set<int> xpos, ypos;
queue<Pii> que; //x,val

int main()
{
    yukari;
    cin >> n >> l >> w;
    for (int i=0,x,y; i<n; i++)
    {
        cin >> x >> y;
        pos.insert({x,y});
        ypos.insert(y);
        xpos.insert(x);
    }
    
    for (auto d: ypos)
    {
        sum = 0;
        for (auto r: xpos)
        {
            auto p = pos.lower_bound({r,d});
            auto q = pos.upper_bound({r,d+l});
            int v = distance(p,q);
            sum += v;
            if (que.front().se < r-w)
                sum -= que.front().fi, que.pop();
            que.push({v,r});
            res = max(res,sum);
        }
    }
    cout <<  res << '\n';
}