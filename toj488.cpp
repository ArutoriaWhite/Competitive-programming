#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;
const int N = 2e5+10;

LL a[N], sum[N], res, k;
int n;

int main()
{
    Eriri
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    for (int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i-1];
    for (int l=0; l<n; l++)
    {
        int r = upper_bound(a,a+n,a[l]+k) - a;
        res = max(res,sum[r]-sum[l]);
    }
    cout << res << '\n';
}
/*
5 0
3
1
2 2
5
*/