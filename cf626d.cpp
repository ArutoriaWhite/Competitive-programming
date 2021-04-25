#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define SZ(x) ((int)x.size())
#define pb push_back
#define int long long
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

const int N = 2010, M = 5010;

int a[N], n, sum[M];
map<int,int> b; // a[i]-a[j] value, cnt

signed main()
{
    ShinraTensei
    cin >> n;
    rep(i,1,n) cin >> a[i];  

    sort(a+1,a+1+n);
    rep(i,1,n)
        rep(j,i+1,n)
            b[a[j]-a[i]]++;
    
    for (auto kvp: b) sum[kvp.ff] = kvp.ss;
    for (auto it=--b.end(); it!=b.begin(); it--)
        sum[prev(it)->ff] += sum[it->ff];

    long long frac = 0;
    for (auto i=b.begin(); i!=b.end(); i++)
        for (auto j=b.begin(); j!=b.end(); j++)
        {
            auto x = b.upper_bound(i->ff+j->ff);
            if (x!=b.end())
                frac += i->ss*j->ss*sum[x->ff];
        }
    int deno = (n*(n-1)/2)*(n*(n-1)/2)*(n*(n-1)/2);

    cout << 1.0*frac/deno << '\n';
}