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

multiset<int> blk;
int t, n, k;
string s;

signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        blk.clear();
        cin >> n >> k >> s;

        int lcnt=0;
        for (int i=0; i<n; i++)
            lcnt += s[i]=='L';
        k = min(k, lcnt);
        if (lcnt==n)
        {
            cout << max(2*k-1,0LL) << '\n';
            continue;
        }

        int i=0;
        while (s[i]=='L') i++;
        for (int clen=0; i<n; i++)
        {
            if (s[i]=='W')
            {
                if (clen>0) blk.insert(clen), clen=0;
            }
            else clen++;
        }
        blk.insert(1e9);
        int res=0;
        while (k>0 && !blk.empty())
        {
            if (k >= *blk.begin())
            {
                res += *blk.begin()*2+1;
                k -= *blk.begin();
                blk.erase(blk.begin());
            }
            else
                res += 2*k, k=0;
        }
        for (int i=0; i<n; i++)
            if (s[i]=='W')
                res += (i>0&&s[i-1]=='W'? 2:1);
        cout << res << '\n';
    }
}