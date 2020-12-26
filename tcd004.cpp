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

int a[N], sum, n, pre[N], k;

void sol (int l, int r, int d)
{
    if (r-l+1<3 || d>=k) return;

    int cur=0;
    for (int i=l,t=0; i<=r; i++,t++)
        cur += a[i]*t;

    int id, minv = 9e18;
    for (int i=l+1; i<r; i++)
    {
        cur -= pre[r]-pre[l-1];
        if (abs(cur) < minv)
        {
            minv = cur;
            id = i;
        }
    }
    sum += a[id];
    sol(l,id-1,d+1);
    sol(id+1,r,d+1);
}

signed main()
{
    ShinraTensei
    cin >> n >> k;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
        pre[i] = pre[i-1] + a[i];
    sol(1,n,0);
    cout << sum << '\n';
}