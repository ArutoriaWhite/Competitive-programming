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
const int N = 37;

int n, p, a[N], sum;
vector<int> A, B;

int qpow (int i, int j)
{
    int res=1;
    for (; j; j>>=1,i=i*i%p)
    {
        if (j&1)
        {
            res = res*i%p;
        }
    }
    return res;
}
void calc (int l, int r, vector<int> &res)
{
    int m = r-l+1;
    for (int t=1; t<(1<<m); t++)
    {
        int x=1;
        for (int i=l,j=0; i<=r; i++,j++)
        {
            if ((1<<j)&t)
            {
                x = x*a[i]%p;
            }
        }
        res.pb(x);
        if (x==1) sum++;
    }
}

signed main()
{
    cin >> n >> p;
    rep(i,1,n) cin >> a[i];
    calc(1,n/2,A);
    calc(n/2+1,n,B);
    sort(B.begin(), B.end());
    for (auto x: A)
    {
        int inv = qpow(x,p-2);
        int cnt = upper_bound(B.begin(), B.end(), inv) - lower_bound(B.begin(), B.end(), inv);
        sum += cnt;
    }
    cout << sum << '\n';
       
}