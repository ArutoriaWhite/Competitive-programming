#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 3e5+10;

int shun[40], ni[40];

void sol (vector<int> &v, int p)
{
    if (p<0 || v.empty()) return;
    vector<int> v0, v1;
    int c0=0, c1=0;
    for (auto i: v)
    {
        if (i&(1LL<<p))
        {
            c1++;
            shun[p] += c0;
            v1.push_back(i);
        }
        else
        {
            c0++;
            ni[p] += c1;
            v0.push_back(i);
        }
    }
    sol(v0, p-1), sol(v1, p-1);
}

signed main()
{
    SakuraMyWife
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sol(v, 33);

    int ans=0, sum=0;
    for (int i=33; i>=0; i--)
    {
        if (ni[i]>shun[i]) ans|=(1LL<<i);
        sum += min(ni[i], shun[i]);
    }
    cout << sum << ' ' << ans << '\n';
}