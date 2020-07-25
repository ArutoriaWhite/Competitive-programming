#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e3+10, M = 1e7;

struct Edg {int u, v; double w;} e[M];
double x[N], y[N];
int p[N], n, m;
double res;

int find (int x)
{
    return (p[x]==x? x:p[x]=find(p[x]));
}

int main()
{
    Eriri
    for (int i=0; i<N; i++)
        p[i] = i;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
        for (int j=i-1; j>=0; j--)
            e[m++] = {i,j,sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) )};
    }
    sort( e, e+m, [](Edg &a, Edg &b){return a.w < b.w;} );
    for (int i=0,cnt=0; i<m&&cnt<n-1; i++)
    {
        int u = e[i].u, v = e[i].v;
        if (find(u) == find(v)) continue;
        cnt++;
        res += e[i].w;
        p[find(u)] = find(v);
    }
    cout << fixed << setprecision(2) << res << '\n';
}