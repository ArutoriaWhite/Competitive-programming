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
const int N = 110;

int a[N];

signed main()
{
    int T; cin >> T;
    while (T--)
    {
        int n, d;
        cin >> n >> d;
        rep(i,1,n) cin >> a[i];
        int need=0;
        rep(i,1,n)
            if (a[i] > d)
                need = 1;
        if (need)
        {
            sort(a+1,a+1+n);
            cout << (a[1]+a[2] <= d? "Yes":"No") << '\n';
        }
        else cout << "Yes\n";
    }
}