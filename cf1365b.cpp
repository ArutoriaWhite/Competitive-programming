#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 510;

int t, n, a[N], tp[N];

signed main()
{
    exploootion
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        int tot=0, x;
        rep(i,1,n) cin >> x, tot+=x;
        if (tot==n||tot==0)
        {
            int flag=1;
            rep(i,1,n-1) if(a[i]>a[i+1]) flag=0;
            cout << (flag? "Yes":"No") << '\n';
        }
        else
            cout << "Yes\n";
    }
}

