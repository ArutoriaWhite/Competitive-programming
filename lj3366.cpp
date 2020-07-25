#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5010, M = 4e5+10;

struct Edg {int v, w, nex;} e[M];
int h[N], cnt, res, k, vis[N], n, m;
void add (int u, int v, int w)
{
    cnt++;
    e[cnt].v = v, e[cnt].w = w, e[cnt].nex = h[u];
    h[u] = cnt;
}
void prim()
{
    priority_queue<Pii, vector<Pii>, greater<Pii> > pq;
    pq.push({0,1});
    while (!pq.empty())
    {
        int u = pq.top().S, d = pq.top().F;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        res += d, k++;
        for (int i=h[u]; i; i=e[i].nex)
            if (!vis[e[i].v])
                pq.push({e[i].w,e[i].v});
    }
}

int main()
{
    cin >> n >> m;
    for (int i=0,x,y,z; i<m; i++)
    {
        cin >> x >> y >> z;
        add(x,y,z);
        add(y,x,z);
    }
    prim();
    if (k != n) cout << "orz\n";
    else cout << res << '\n';
}
/*
4 5
1 2 2
1 3 2
1 4 3
2 3 4
3 4 3
*/