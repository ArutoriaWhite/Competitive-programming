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
const int N = 2e5+10;

int n, k, m, rsv[N], t;
vector<int> v;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        memset(rsv,0,sizeof(rsv));
        v.clear();

        cin >> n >> k >> m;
        rep(i,1,m)
        {
            int b; cin >> b;
            rsv[b] = 1;
        }

        if ((n-m) % (k-1))
        {
            cout << "NO\n";
            continue;
        }

        int tot = 0;
        for (int i=1,len=0; i<=n+1; i++)
        {
            if (i==n+1 || rsv[i])
            {
                v.pb(len);
                tot += v.back();
                len = 0;
            }
            else
            {
                len++;
            }
        }
        /* for (auto x: v) de(x); dd */

        int flag = 1;
        while (!v.empty() && tot>0)
        {
            int len0 = 0;
            while (!v.empty() && len0 < k/2)
            {
                len0 += v.back();
                v.pop_back();
            }

            int len1 = 0;
            while (!v.empty() && len1 < k/2)
            {
                len1 += v.back();
                v.pop_back();
            }

            if (len0 < k/2 || len1 < k/2)
            {
                flag = 0;
                break;
            }
            else
            {
                if (len1 - k/2 > 0)
                    v.pb(len1 - k/2);
                if (len0 - k/2 > 0)
                    v.pb(len0 - k/2);
                tot -= len0;
                tot -= len1;
            }
/*             de(len0), de(len1), dd
            for (auto x: v) de(x); dd */
        }

        if (!flag) cout << "NO\n";
        else cout << "YES\n";

    }
}
/*
4
3 3 1
1
7 3 3
1 5 7
10 5 3
4 5 6
13 7 7
1 3 5 7 9 11 12

1
7 3 3
1 5 7

1
3 3 1
1
*/