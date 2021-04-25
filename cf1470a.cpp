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
/*
n, m < 3e5
there is n requirements r[1]...r[n]
and m gifts c[1]...c[m], increasing

for requirement i, choose one from c[1]...c[r[i]]
or just cost c[r[i]]

a gift can only be choosed once

find min cost

sort r
i greater, cost of i greater
cost of i at least c[r[i]]
*/
const int N = 3e5+10;

int r[N], c[N];
int n, m, t;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,1,n) cin >> r[i];
        rep(i,1,m) cin >> c[i];
        sort(r+1,r+1+n);

        int res=0;
        for (int i=n,j=1; i>0; i--)
        {
            if (r[i]>=j) res += c[j], j++;
            else res += c[r[i]];
        }
        cout << res << '\n';
    }
}
/*
考慮如何證明一個貪心?

1. 假設存在更好的方法，則原本的方法會不符合貪心的定義
*/