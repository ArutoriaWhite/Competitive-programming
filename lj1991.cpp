#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 510, M = 1000000;

double ans;
int px[N], py[N];
struct Edg
{
    double u, v, w;
}e[M];

int pa[N], s, p, m;
int find (int a) { return (pa[a]==a? a : pa[a]=find(pa[a])); }
void U (int a, int b) { pa[find(a)] = find(b); }

int main()
{
    cin >> s >> p;
    for (int i=0; i<p; i++)
    {
        cin >> px[i] >> py[i];
        for (int j=0; j<i; j++)
            e[m++] = {i,j,sqrt(pow(px[i]-px[j],2) + pow(py[i]-py[j],2)) };
    }
    sort(e,e+m,[](Edg &a, Edg &b){return a.w < b.w;});
    for (int i=0; i<p; i++) pa[i] = i;
    for (int i=0,k=0; i<m; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            k++, U(e[i].u, e[i].v), ans = e[i].w;
            if (k >= p-s)
            {
                cout << fixed << setprecision(2) << ans << '\n';
                return 0;
            }
        }
    }
}