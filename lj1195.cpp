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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e3+10, M = 1e4+10;

int p[N], n, m, k, cnt, res;
struct Edge {int u, v, w;} edges[M];
inline bool cmp (Edge a, Edge b)
{
    return a.w < b.w;
}
inline int find (int x)          
{
    return (x==p[x]? x : p[x]=find(p[x]));
}
inline void U (int a, int b)
{
    p[find(a)]=find(b);
}

void krus()
{
    for (int i=0; i<N; i++) p[i] = i;
    cnt = n;
    sort(edges,edges+m,cmp);
    for (int i=0; i<m&&cnt>k; i++)
    {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) == find(v)) continue;
        U(u,v);
        res += w, cnt--;
    }
}

int main()
{
    yukari;
    cin >> n >> m >> k;
    for (int i=0,x,y,l; i<m; i++)
    {
        cin >> x >> y >> l;
        edges[i] = {x,y,l};
    }
    krus();
    if (cnt==k)
        cout << res << '\n';
    else
        cout << "No Answer\n";
}