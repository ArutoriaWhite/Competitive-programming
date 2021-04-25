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
const int N = 5e4+10;

int p[N], n, k;

int legal (int r)
{
    int cnt=0, rbound=-1;
    rep(i,1,n)
    {
        if (rbound < p[i])
        {
            rbound = p[i]+r;
            cnt++;
        }
    }
    return cnt <= k;
}
int bs ()
{
    int i=0, s = 1e9;
    while (s > 0)
    {
        if (legal(i+s)) s>>=1;
        else i += s;
    }
    return i+1;
}

signed main()
{
    cin >> n >> k;
    rep(i,1,n) cin >> p[i];
    sort(p+1, p+1+n);
    cout << bs() << '\n';
}