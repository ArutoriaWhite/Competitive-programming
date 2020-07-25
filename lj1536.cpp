#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

int n, m;

struct Dsu
{
    int p[N];
    void init() { for(int i=0; i<N; i++) p[i] = i; }
    int find (int x) { return (x==p[x]? x : find(p[x])); }
    void U (int x, int y) { p[find(x)] = find(y); }
    int cnt()
    {
        int res = 0;
        for (int i=1; i<=n; i++) res += (p[i]==i);
        return res;
    }
} dsu;

int main()
{
    Eriri
    while (cin >> n && n)
    {
        cin >> m;
        dsu.init();
        for (int i=0,u,v; i<m; i++)
        {
            cin >> u >> v;
            dsu.U(u,v);
        }
        cout << dsu.cnt()-1 << '\n';
    }
}