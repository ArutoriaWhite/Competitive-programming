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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int t, p, q, np[N];

int countd (int i, int j)
{
    int res = 0;
    while (i%j == 0) res++, i/=j;
    return res;
}
void find_div (vector<int> &divs, int x)
{
    for (int i=1; i<=sqrt(x); i++)
    {
        if (!np[i] && x%i == 0)
        {
            divs.pb(i);
        }
        if (x%i==0 && x/i>sqrt(x))
        {
            divs.pb(x/i);
        }
    }
}
int divi (int i, int j, int k)
{
    while (k--) i /= j;
    return i;
}

signed main()
{
    SakuraMyWife
    np[1]=1;
    for (int i=2; i<N; i++)
        for (int j=i*i; j<N; j+=i)
            np[j] = 1;
    cin >> t;
    while (t--)
    {
        cin >> p >> q;
        if (p%q) cout << p << '\n';
        else
        {
            int res = 0;
            vector<int> divs;
            find_div(divs, q);
            for (auto d: divs)
            {
                int i = countd(p,d);
                int j = countd(q,d);
                //de(d), de(i), de(j), dd;
                res = max(res, divi(p,d,i-j+1));
            } 
            cout << res << '\n';
        }
    }
}