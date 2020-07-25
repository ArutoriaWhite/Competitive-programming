#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e3+10;

int n, vis[N];
long long x[N], y[N], d[N];

long long calc (int i, int j)
{
    return (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
}

double prim()
{
    double res = 0;
    for (int i=1; i<=n; i++)
        d[i] = 1e14;
    d[1] = 0;
    for (int i=1; i<=n; i++)
    {
        int u = -1;
        for (int i=1; i<=n; i++)
            if ( !vis[i] && (u==-1 || d[i]<d[u]) )
                u = i;
        if (u == -1) break;
        vis[u] = 1;
        res += sqrt(d[u]);
        for (int i=1; i<=n; i++)
        {
            if (i != u && !vis[i])
                d[i] = min(d[i], calc(i,u));
        }
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    cout << fixed << setprecision(2) << prim() << '\n';
}