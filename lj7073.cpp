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
const int N = 1e6+10;

int n, q, x;
int a[N], val[N], dp[N], pos[N];
int br[N], fa[N];

// 0, 1, 2:!, 3:|, 4:&

void read (stringstream &ss)
{
    char c;
    while (ss >> c)
    {
        if (c == 'x')
        {
            int x; ss >> x;
            pos[x] = ++n;
        }
        else if (c == '!') a[++n] = 2;
        else if (c == '|') a[++n] = 3;
        else a[++n] = 4;
    }
}
int build (int i)//return end, val
{
    int u = a[i], l=i-1, r=0, rt;
    if (u>2)
    {
        r  = build(l);
        rt = build(r);
        if (u==3) val[i]=val[l]||val[r];
        if (u==4) val[i]=val[l]&&val[r];
    }
    else if (u==2)
    {
        rt = build(l);
        val[i] = !val[l];
    }
    else
    {
        rt = l;
        val[i] = a[i];
    }
    fa[l] = fa[r] = i;
    br[l] = r, br[r] = l;
    return rt;
}
void calc_dp()
{
    dp[n] = 1;
    for (int i=n-1; i>0; i--)
    {
        if (a[fa[i]]==2)
            dp[i] = dp[fa[i]];
        if (a[fa[i]]==3)
            dp[i] = (val[br[i]]? 0:dp[fa[i]]);
        if (a[fa[i]]==4)
            dp[i] = (val[br[i]]? dp[fa[i]]:0);
    }
}

signed main()
{
    SakuraMyWife
    string s;
    stringstream ss;
    getline(cin, s);
    ss.str(s);
    read(ss);
    cin >> x;
    rep(i,1,x) cin >> a[pos[i]];
    build(n);
    calc_dp();
/*     rep(i,1,n)
    {
        de(i), de(a[i]), de(val[i]), de(fa[i]), de(br[i]), de(dp[i]), dd;
    } */
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << (dp[pos[x]]? !val[n]:val[n]) << '\n';
    }
}