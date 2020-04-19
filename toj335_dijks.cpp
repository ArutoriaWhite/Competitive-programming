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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e5+10, M = 1e6+10;

struct Edge {int a, b, w;} edges[M];
vector<Pii> adj[N];
int p[N];

inline int find (int u)
{
    return (p[u]==u? u : p[u]=find(p[u]));
}
inline void U (int a, int b)
{
    p[find(a)] = find(b);
}