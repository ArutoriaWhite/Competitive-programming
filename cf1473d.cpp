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

int t, n, m;
int a[N], sum[N], premin[N], sufmin[N], premax[N], sufmax[N];

void build()
{
    mem(sum,0);
    mem(premin,0);
    mem(premax,0);
    mem(sufmin,0);
    mem(sufmax,0);

    rep(i,1,n) sum[i] = sum[i-1]+a[i];
    rep(i,1,n) // max of 0, a1, a1+a2, .., a1+a2+...+ai
    {
        premin[i] = min(premin[i-1], sum[i]);
        premax[i] = max(premax[i-1], sum[i]);
    }
    for (int i=n; i>0; i--) // max of 0, a[i], a[i]+a[i+1], .. , a[i]+..+a[n]
    {
        sufmin[i] = min(sufmin[i+1], 0LL) + a[i];
        sufmax[i] = max(sufmax[i+1], 0LL) + a[i];
    }
}

int query (int l, int r)
{
    int mna = premin[l-1];
    int mxa = premax[l-1];
    int mnb = sufmin[r+1];
    int mxb = sufmax[r+1];
    mnb += sum[l-1];
    mxb += sum[l-1];
    return max(mxa,mxb) - min(mna,mnb) + 1;
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        rep(i,1,n)
        {
            char c;
            cin >> c;
            a[i] = (c=='+'? 1:-1);
        }

        build();

        while (m--)
        {
            int l, r;
            cin >> l >> r;
            cout << query(l,r) << '\n';
        }
    }
}
/*
2
8 4
-+--+--+
1 8
2 8
2 5
1 1
4 10
+-++
1 1
1 2
2 2
1 3
2 3
3 3
1 4
2 4
3 4
4 4


1
8 4
-+--+--+
1 8
2 8
2 5
1 1
*/