#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define Exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

vector<pii> v;
int n;

signed main()
{
    Exploootion
    cin >> n;
    rep(i,1,n)
    {
        int l, r;
        cin >> l >> r;
        v.eb(l,1);
        v.eb(r,-1);
    }
    sort(v.begin(), v.end());
    int cur=0, ay, aval=0;
    for (auto x: v)
    {
        cur += x.ss;
        if (aval < cur)
        {
            ay = x.ff;
            aval = cur;
        }
    }
    cout << ay << ' ' << aval << '\n';
}