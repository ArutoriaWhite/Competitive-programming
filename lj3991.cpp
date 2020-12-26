#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

struct Treap
{
    int l[N], r[N], pri[N], sz[N], rev[N], cnt;
    int node()
    {
        cnt++;
        pri[cnt] = rand();
        sz[cnt] = 1;
        return cnt;
    }
    void push (int u)
    {
        if (rev[u]%2==0) return;
        rev[u] = 0;
        swap(l[u], r[u]);
        rev[l[u]]++;
        rev[r[u]]++;
    }
    void pull (int u)
    {
        sz[u] = sz[l[u]] + sz[r[u]] + 1;
    }
    void split (int u, int k, int &a, int &b)
    {
        if (!u)
        {
            a = b = 0;
            return;
        }
        push(u);
        if (k<=sz[l[u]])
        {
            b = u;
            split(l[u],k,a,l[u]);
        }
        else
        {
            a = u;
            split(r[u],k-sz[l[u]]-1,r[u],b);
        }
        pull(u);
    }
    int merge (int a, int b)
    {
        if (a==0) return b;
        if (b==0) return a;
        push(a), push(b);
        if (pri[a] < pri[b])
        {
            r[a] = merge(r[a], b);
            pull(a);
            return a;
        }
        else
        {
            l[b] = merge(a,l[b]);
            pull(b);
            return b;
        }
    }
    void print (int u)
    {
        if (u==0) return;
        push(u);
        print(l[u]);
        cout << u << ' ';
        print(r[u]);
    }
} tp;

int n, m, rt;

signed main()
{
    ShinraTensei
    cin >> n >> m;
    rep(i,1,n)
    {
        rt = tp.merge(rt, tp.node());
    }
    rep(i,1,m)
    {
        int l, r;
        cin >> l >> r;
        int a1, b1, a2, b2;
        tp.split(rt,l-1,a1,b1);
        tp.split(b1,r-l+1,a2,b2);
        tp.rev[a2]++;
        rt = tp.merge(a1,tp.merge(a2,b2));
    }
    tp.print(rt);
    cout << '\n';
}