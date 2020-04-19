#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 110;

struct Edge {int a, b, w;} edges[N];z
inline bool cmp (Edge x, Edge y)
{
    return x.w < y.w;
}
int p[N], r, sum, k, n;

inline int find (int x)
{
    return (x==p[x]? x : p[x]=find(p[x]));
}
inline void U (int a, int b)
{
    p[find(a)] = find(b);
}

inline int krus ()
{
    for (int i=0; i<=n; i++)
        p[i] = i;
    sort(edges,edges+r,cmp);
    int res = 0;
    for (int i=0; i<r; i++)
    {
        if (find(edges[i].a) != find(edges[i].b))
        {
            U(edges[i].a,edges[i].b);
            res += edges[i].w;
        }
    }
    return res;
}

int main()
{
    yukari;
    cin >> n >> k;
    for (int u,v,w,i; i<k; i++)
    {
        cin >> u >> v >> w;
        if (w!=0)
            edges[r++] = {u,v,w}, sum += w;
    }
    cout << sum-krus() << '\n';
}