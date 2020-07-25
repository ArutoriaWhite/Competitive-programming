#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 20010;

int n, m, k;
string s, s1, s2;
struct Dsu
{
    int p[N];
    inline void init()
    {
        for (int i=0; i<N; i++) p[i] = i;
    }
    inline int find (int x)
    {
        return (p[x]==x? x : p[x]=find(p[x]));
    }
    inline void U (int x, int y)
    {
        p[find(x)] = find(y);
    }
} dsu;
map<string,int> id;

int main()
{
    Eriri
    dsu.init();
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> s;
        id[s] = i;
    }
    for (int i=0; i<m; i++)
    {
        cin >> s1 >> s2;
        dsu.U(id[s1],id[s2]);
    }
    cin >> k;
    for (int i=0; i<k; i++)
    {
        cin >> s1 >> s2;
        cout << (dsu.find(id[s1])==dsu.find(id[s2])? "Yes." : "No.") << '\n';
    }
}