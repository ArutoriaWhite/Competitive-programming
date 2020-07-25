#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

int n, cnt, up, lw, h[N];
struct edg {int to, w, nx;} e[N<<1];
inline void add (int u, int v, int w){
    cnt++;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].nx = h[u];
    h[u] = cnt;
}

int dp (int u, int p, int sum)
{
    if (lw<=sum && sum<=up) return 1;
    if (up < sum) return 0;
    for (int i=h[u]; i; i=e[i].nx)
        if (e[i].to != p)
            if (dp(e[i].to, u, sum+e[i].w))
                return 1;
    return 0;
}

int main()
{
    Eriri
    cin >> n >> lw >> up;
    for (int i=0,u,v,w; i<n-1; i++)
    {
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    if (dp(0,0,0)) cout << "Eat Eat Eat\n";
    else cout << "Go find other chickens\n";
}
/*
4
2 3
0 1 1
0 2 2
2 3 3
*/