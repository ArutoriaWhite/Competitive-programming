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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e3+10, M = 1e5+10;

int p[N], n, m, cnt, t;
struct Edge {int x, y, w;} edges[M];
inline int find (int a)
{
    return (p[a]==a? a : p[a]=find(p[a]));
}
inline void U (int a, int b)
{
    p[find(a)] = find(b);
}

int main()
{
    yukari;
    cin >> n >> m;
    for (int i=0; i<n; i++) p[i] = i;
    for (int i=0,x,y,z; i<m; i++)
    {
        cin >> x >> y >> z;
        edges[i] = {x,y,z};
    }
    sort(edges,edges+m,[](Edge a, Edge b){return a.w<b.w;});
    cnt = n, t = -1;
    for (int i=0; i<m&&cnt>1; i++)
    {
        int a = edges[i].x, b = edges[i].y;
        t = edges[i].w;
        if (find(a) != find(b)) cnt--, U(a,b);
    }
    if (cnt > 1) t = -1;
    cout << t << '\n';
}