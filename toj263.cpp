#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

int l[N], r[N], sz[N], v[N], mx[N], pr[N], cnt, n, q, rt;

int node (int x)
{
    ++cnt;
    l[cnt] = r[cnt] = 0;
    sz[cnt] = 1;
    v[cnt] = mx[cnt] = x;
    pr[cnt] = rand();
    return cnt;
}
void pull (int u)
{
    sz[u] = sz[l[u]] + sz[r[u]] + 1;
    mx[u] = max(v[u], max(mx[l[u]], mx[r[u]]));
}
void split (int u, int k, int &a, int &b)
{   
    if (!u) a = b = 0;
    else if (k<=sz[l[u]])
        b = u, split(l[u], k, a, l[b]), pull(u);
    else
        a = u, split(r[u], k-1-sz[l[u]], r[a], b), pull(u);
}
int merge (int a, int b)
{  
    if (!a || !b) return (a? a : b);
    if (pr[a] < pr[b])
    {
        r[a] = merge(r[a], b);
        pull(a);
        return a;
    }
    else
    {
        l[b] = merge(a, l[b]);
        pull(b);
        return b;
    }
}
signed main()
{
    XinAi
    while(cin >> n >> q)
    {
        mx[0] = -2e9;
        rt = cnt = 0;
        for (int i=1,x; i<=n; i++)
            cin >> x, rt = merge(rt, node(x));
        for (int i=1; i<=q; i++)
        {
            int t, x, y, a, b, a1, b1;
            cin >> t;
            if (t == 1 && cin >> x >> y)
            {
                split(rt, x-1, a, b);
                split(b, 1, a1, b1);
                rt = merge(a, merge(node(y), b1));
            }
            if (t == 2 && cin >> x >> y)
            {
                split(rt, x-1, a, b);
                split(b, y-x+1, a1, b1);
                cout << mx[a1] << '\n';
                rt = merge(a, merge(a1, b1));
            }
            if (t == 3 && cin >> x >> y)
            {
                split(rt, x-1, a, b);
                rt = merge(a, merge(node(y), b));
            }
            if (t == 4 && cin >> x)
            {
                split(rt, x-1, a, b);
                split(b, 1, a1, b1);
                rt = merge(a, b1);
            }
        }        
    }

}