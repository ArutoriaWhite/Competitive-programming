#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e5;

vector<int> adj[N];
int n, m, k, atk[N], res[N];
unordered_set<int> rest;
struct Dsu
{
    int p[N], ans=0;
    inline void init(){
        for (int i=0; i<N; i++) p[i] = i;
    }
    int find (int x){
        return (p[x]==x? x : p[x]=find(p[x]));
    }
    void U (int u, int v)
    {
        if (find(u)!=find(v))
        {
            ans--;
            p[find(u)] = find(v);
        }
    }
    
} dsu;

int main()
{
    Eriri
    cin >> n >> m;
    dsu.init();
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    for (int i=0; i<k; i++) cin >> atk[i];
    for (int i=0; i<n; i++) rest.insert(i);
    for (int i=0; i<k; i++) rest.erase(atk[i]);
    dsu.ans = rest.size();
    for (auto u: rest)
        for (auto v: adj[u])
            if (rest.find(v) != rest.end())
                dsu.U(u,v);
    
    for (int i=k-1,j=0; i>=0; j++,i--)
    {
        res[j] = dsu.ans;
        rest.insert(atk[i]);
        dsu.ans++;
        for (auto v: adj[atk[i]])
            if (rest.find(v) != rest.end())
                dsu.U(atk[i],v);
    }
    cout << dsu.ans << '\n';
    for (int i=k-1; i>=0; i--)
        cout << res[i] << '\n';
}