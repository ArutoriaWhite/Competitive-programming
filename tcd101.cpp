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
const int N = 1e5+10;

int n, q;
int a[N], len[N], fa[N];
multiset<int> s;

int find (int x)
{
    return (fa[x]==x? x:fa[x]=find(fa[x]));
}
void merge (int i, int j) // merge i to j, check if i is legal
{
    if (i<1 || i>n || !a[i]) return;
    i = find(i);
    j = find(j);

    s.erase(s.lower_bound(len[i]));
    s.erase(s.lower_bound(len[j]));
    s.insert(len[j]+len[i]);
    len[j] += len[i];

    fa[i] = fa[j];
}

void fill (int i)
{
    fa[i] = i, len[i] = 1, a[i] = 1, s.insert(1);
    merge(i-1,i);
    merge(i+1,i);
}

signed main()
{
    ShinraTensei
    cin >> n >> q;
    rep(i,1,n)
    {
        int x; cin >> x;
        if (x) fill(i);
    }

    int ans1 = (s.empty()? 0:*s.rbegin());
    int ans2 = (s.empty()? 0:*s.begin());

    rep(i,1,q)
    {
        int x; cin >> x;
        fill(x);
        ans1 += *s.rbegin();
        ans2 += *s.begin();
    }
    cout << ans1 << '\n' << ans2 << '\n';
}