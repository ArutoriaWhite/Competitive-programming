#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

vector<int> ene[N];
int p[N], n, m, res;

inline void init()
{
    for (int i=0; i<N; i++)
        p[i] = i;
}
inline int find(int x)
{
    return (x==p[x]? x : p[x]=find(p[x]));
}
inline void U (int x, int y)
{
    p[find(x)] = find(y);
}

int main()
{
    init();
    cin >> n >> m;
    char c; int a, b;
    while (m--)
    {
        cin >> c >> a >> b; 
        if (c=='F')
            U(a,b);
        else
        {
            for (auto e: ene[a]) U(b,e);
            for (auto e: ene[b]) U(a,e);
            ene[a].push_back(b);
            ene[b].push_back(a);
        }
    }
    for (int i=1; i<=n; i++)
        res += (p[i]==i);
    cout << res << '\n';
}