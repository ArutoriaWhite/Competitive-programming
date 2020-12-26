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

int t, n, m, tar;
vector<int> rem;

int calc (int k) // count the amount less than k
{
    return k - (lower_bound(rem.begin(), rem.end(), k)-rem.begin());
}
int bs()
{
    sort(rem.begin(), rem.end());
    int i=0, s=(1LL<<m)-1;
    while (s > 0)
    {
        //de(i), de(s), de(i+s), de(calc(i+s)), dd;
        if ((unsigned long long)(i+s) >= (unsigned long long)(1LL<<m) || calc(i+s) > tar)
            s >>= 1;
        else
            i += s;
    }
    return i;
}
int toi (string s)
{
    int res=0;
    for (int i=0; i<SZ(s); i++)
    {
        res *= 2;
        res += s[i]=='1';
    }
    return res;
}
string tos (int x)
{
    string s;
    while (x>0)
    {
        s.pb((x&1)? '1':'0');
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}
/*
1 2 3 4 5
0 1 2 3 4
1 2 3 4
0 1 2 3 
*/
signed main()
{
    SakuraMyWife
    cin >> t;
    while (t--)
    {
        rem.clear();
        cin >> n >> m;
        tar = ((1LL<<m)-n-1)/2;
        for (int i=0; i<n; i++)
        {
            string s;
            cin >> s;
            rem.pb(toi(s));
        }
        //de(tar), dd;
        string ans = tos(bs());
        cout << setw(m) << setfill('0') << ans << '\n';
        //for (auto x: rem) cout << x << ' ';
        //cout << '\n';
    }    
}
/*
1 3 4 5 6

*/