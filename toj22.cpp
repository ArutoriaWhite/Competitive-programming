#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1010;

Pii arr[N];
int n, p, q, res, f=1;

int main()
{
    yukari;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i].fi >> arr[i].se;
    sort(arr,arr+n);
    p = arr[0].fi, q = arr[0].se;
    for (int i=1; i<n&&f; i++)
    {
        if (arr[i].fi > q+1) f=0;
        if (arr[i].se <= q) continue;
        if (arr[i].fi > p+1)
            res++, p = q;
        q = arr[i].se;
    }
    if (!f) cout << "NO\n";
    else cout << res+1 << '\n';
}