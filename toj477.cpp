#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define QQai ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

Pii a[N];
int b[N], n, k, x, tot, sum, need;

signed main()
{
    QQai
    cin >> n >> k >> x;
    for (int i=1; i<=n; i++) cin >> a[i].F, sum += a[i].F;
    for (int i=1; i<=n; i++) cin >> a[i].S, need += a[i].S;
    for (int i=1; i<=n; i++) b[i] = a[i].F - a[i].S*x;
    sort(b+1, b+1+n);
    for (int i=n,tot=n*k; i>0&&b[i]>0&&tot-k>=need; sum-=b[i],i--,tot-=k);
    cout << sum << '\n';
}
/*
3 2 4
1 2 3
1 2 1
3 2 1
1 2 3
1 2 1
*/