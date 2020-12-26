#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 2e5+10;

int sz[N], v[N], l[N], r[N], pr[N], sum[N];
int n, q, cnt, rt;

int node (int _v)
{
    cnt++, v[cnt] = _v, pr[cnt] = rand(), sz[cnt] = 1, sum[cnt] = _v;
    return cnt;
}
void up (int u)
{
    sz[u] = sz[l[u]] + sz[r[u]] + 1;
    sum[u] = sum[l[u]] + sum[r[u]] + v[u];
}
int merge (int u, int v)
{
    if (!u || !v) return (u? u : v);
    if (pr[u] < pr[v])
    {
        r[u] = merge(r[u],v);
        up(u);
        return u;        
    }
    else
    {
        l[v] = merge(u,l[v]);
        up(v);
        return v;        
    }

}
void split (int u, int k, int &a, int &b)
{
    if (!u) a = b = 0;
    else if (k <= sz[l[u]])
        b = u, split(l[u],k,a,l[b]), up(u);
    else
        a = u, split(r[u],k-1-sz[l[u]],r[a],b), up(u);
}

void print()
{
    for (int i=1; i<=n; i++)
        de(i), de(l[i]), de(r[i]), de(sz[i]), de(v[i]), de(sum[i]), dd
}

signed main()
{
    Eriri
    cin >> n;
    for (int i=1,a; i<=n; i++)
    {
        cin >> a;
        rt = merge(rt,node(a));
    }
    cin >> q;
    for (int i=1,a,b; i<=q; i++)
    {
        cin >> a >> b;
        if (a > b) swap(a,b);
        int x,y,x1,y1;
        split(rt,a-1,x,y), split(y,b-a+1,x1,y1);
        cout << sum[x1] << '\n';
        rt = merge(merge(x,x1),y1);
    }
}