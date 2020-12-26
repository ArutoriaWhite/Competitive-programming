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

int a[N], n, t;

int all_same()
{
    rep(i,1,n-1)
        if (a[i]!=a[i+1])
            return 0;
    return 1;
}

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        cin >> n;
        rep(i,1,n) cin >> a[i];
        if (all_same()) cout << -1 << '\n';
        else
        {
            int mx=0;
            rep(i,1,n) mx=max(mx,a[i]);
            rep(i,1,n) 
            {
                if (a[i]==mx)
                {
                    if (i-1>0 && a[i-1]!=a[i])
                    {
                        cout << i << '\n';
                        break;
                    }
                    if (i+1<=n && a[i+1]!=a[i])
                    {
                        cout << i << '\n';
                        break;                        
                    }
                }
            }
        }
    }
}
/*
5 5 4 3 2 1
*/