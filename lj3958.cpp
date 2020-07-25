#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

int t, n, h, r;
struct Nod
{
    int x, y, z;
} nods[N];

struct Dsu
{
    int p[N];
    inline void init(){
        for (int i=0; i<N; i++) p[i] = i;
    }
    inline int find (int x){
        return (p[x]==x? x : p[x]=find(p[x]));
    }
    inline void U (int x, int y){
        p[find(x)] = find(y);
    }
} dsu;

inline bool con (int i, int j){
    return sqrt( pow(nods[i].x-nods[j].x,2) + pow(nods[i].y-nods[j].y,2) + pow(nods[i].z-nods[j].z,2) ) <= r*2;
}
inline bool bot_abov (){
    for (int i=1; i<=n; i++)
        if (nods[i].z<=r && dsu.find(i)==dsu.find(0))
            return 1;
    return 0;
}

signed main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        dsu.init();
        cin >> n >> h >> r;
        for (int i=1; i<=n; i++)
            cin >> nods[i].x >> nods[i].y >> nods[i].z;
        for (int i=1; i<=n; i++)
        {
            if (h-nods[i].z<=r) dsu.U(0,i);
            for (int j=1; j<i; j++)
                if (con(i,j)) dsu.U(i,j);
        }
        cout << (bot_abov()? "Yes" : "No") << '\n';
    }
}