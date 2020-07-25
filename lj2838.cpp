#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 210;

int n, res, adj[N][N], nd[N];
struct Dsu
{
    int p[N];
    inline void init(){
        for (int i=0; i<N; i++)
            p[i] = i;
    }
    inline int find (int x){
        return (p[x]==x? x : p[x]=find(p[x]));
    }
    inline void U (int a, int b){
        p[find(a)] = find(b);
    }
} dsu;

int main()
{
    dsu.init();
    cin >> n;
    for (int i=1,j; i<=n; i++)
        while (cin >> j && j)
            adj[i][j] = 1;
    for (int k=1; k<n; k++)
        for (int i=1; i+k<=n; i++)
            for (int j=i; j<=i+k; j++)
            {
                adj[i][i+k] |= adj[i][j]&&adj[j][i+k];
                adj[i+k][i] |= adj[j][i]&&adj[i+k][j];
            }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (adj[i][j] && dsu.find(i)!=dsu.find(j))
                dsu.p[j] = i;
    for (int i=1; i<=n; i++)
        res += (dsu.p[i]==i);
    cout << res << '\n';
}