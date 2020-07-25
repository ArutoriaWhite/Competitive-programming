#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

int a[N], n, m, ans;
long long pre[N<<1], st[N<<2];

void build()
{
    for (int i=0; i<m; i++) st[i+m] = pre[i+1];
    for (int i=m-1; i>0; i--) st[i] = min( st[i*2], st[i*2+1]);
}
int query (int l, int r)
{
    long long res = 2e10;
    for (l+=m,r+=m; l<r; l>>=1,r>>=1)
    {
        if (l&1) res = min( res, st[l++]);
        if (r&1) res = min( res, st[--r]);
    }
    return res;
}

int main()
{
    Eriri
    cin >> n;
    m = 2*n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        pre[i] = pre[i-1] + a[i-1];
    for (int i=1; i<=n; i++)
        pre[i+n] = pre[i+n-1] + a[i-1];
    build();
    for (int i=0; i<n; i++)
        if (query(i,i+n) >= pre[i])
            ans++;
    cout << ans << '\n';
}