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
const int N = 2010;

/*
give a array a

set x
while (!a.empty())
    find a[i] + a[j] = x
    remove a[i], a[j];
    x = max(a[i], a[j])

n <  1000
a[i] < 1e6

find available x

for all i, x greater then a[i]

if same two number must be removed in the same time

the x will be less and less, but always must be the max number in the array
if not choosing the max number in the array, there will be no way to remove the greater numbers

is the initial x matter? enum
n*nlogn
*/

int n, t, a[N];
vector<pii> steps;
multiset<int> s;

int check (int x, int mix)
{
    int mx = a[mix];
    steps.clear();
    s.clear();
    rep(i,1,n)
        if (i != mix)
            s.insert(a[i]);
    while (!s.empty())
    {
        auto k = s.lower_bound(x - mx);
        if (k==s.end() || *k!=x - mx) return 0;
        steps.pb({*k,mx});
        //de(*k), de(mx), dd;
        s.erase(k);
        if (s.empty()) break;
        x = mx;
        mx = *s.rbegin();
        s.erase(s.lower_bound(mx));
    }
    return 1;
}
void solve ()
{
    int mxi=1;
    rep(i,1,n)
        if (a[i] >= a[mxi])
            mxi = i;
    //de(mxi), dd;
    rep (i,1,n)
    {
        if (i == mxi) continue;
        int x = a[i] + a[mxi];
        //de(x), dd;
        if (check(x, mxi))
        {
            cout << "YES\n";
            cout << x << '\n';
            for (auto p: steps)
                cout << p.ff << ' ' << p.ss << '\n';
            return;
        }
    }
    cout << "NO\n";
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        cin >> n, n*=2;
        rep(i,1,n) cin >> a[i];
        solve();
    }
}
/*
4
2
3 5 1 2
3
1 1 8 8 64 64
2
1 1 2 4
5
1 2 3 4 5 6 7 14 3 11

1
2
3 5 1 2
*/