#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5010;

int n, m, p;
struct Dsu
{
    int p[N];
    void init()
    {
        for (int i=0; i<N; i++) p[i] = i;
    }
    int find (int x)
    {
        return (p[x]==x? x : p[x]=find(p[x]));
    }
    void U (int x, int y)
    {
        p[find(x)] = find(y);
    }
} dsu;

int main()
{
    Eriri
    dsu.init();
    cin >> n >> m >> p;
    for (int i=0,u,v; i<m; i++)
    {
        cin >> u >> v;
        dsu.U(u,v);
    }
    for (int i=0,u,v; i<p; i++)
    {
        cin >> u >> v;
        cout << (dsu.find(u)==dsu.find(v)? "Yes" : "No") << '\n';
    }
}