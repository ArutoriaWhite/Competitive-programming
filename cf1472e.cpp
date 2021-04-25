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
there's n h and w
for every i find a j such that:
h[j] < h[i] && w[j] < w[i]
or
h[j] < w[i] && w[j] < h[i]

let every i, w[i] <= h[i]

in all j that h[j] < h[i], find w[j] < w[i];

sort as h

enum 1..n as i
*/
const int N = 2e5+10;
map<int,int> mp; //w, index
int n, t, ans[N];
pair<pii,int> a[N]; //h, w, index; h>=w

int cmp (pair<pii,int> i, pair<pii,int> j)
{
    if (i.ff.ff != j.ff.ff) return i.ff.ff < j.ff.ff;
    else return i.ff.ss > j.ff.ss;
    return 0;
}

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        mp.clear();
        cin >> n;
        rep(i,1,n)
        {
            cin >> a[i].ff.ff >> a[i].ff.ss;
            a[i].ss = i;
        }
        rep(i,1,n)
            if (a[i].ff.ff < a[i].ff.ss)
                swap(a[i].ff.ff, a[i].ff.ss);
        sort(a+1,a+1+n,cmp);

        rep(i,1,n)
        {
            auto kvp = mp.lower_bound(a[i].ff.ss);
            if (mp.empty() || kvp == mp.begin()) ans[a[i].ss] = -1;
            else ans[a[i].ss] = prev(kvp)->ss;
            mp[a[i].ff.ss] = a[i].ss;
        }
        rep(i,1,n) cout << ans[i] << ' ';
        cout << '\n';
    }
}