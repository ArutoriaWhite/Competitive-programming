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
const int M = 1e9+7;

int pp[200005];
int len1[5], len2[5], len3[5];
int n, tot;
string s;

signed main()
{
    SakuraMyWife
    pp[0] = 1;
    rep(i,1,200000) pp[i] = pp[i-1]*3%M;

    cin >> n >> s;
    for (int i=n-1; i>=0; i--)
    {
        if (s[i]=='a')
        {
            len3[0] += len2[0];
            len3[1] += len2[1];
            len3[2] += len2[2];
        }
        if (s[i]=='b')
        {
            len2[0] += len1[0];
            len2[1] += len1[1];
        }
        if (s[i]=='c')
        {
            len1[0] ++;
        }
        if (s[i]=='?')
        {
            tot++;
            len3[1] += len2[0];
            len3[2] += len2[1];
            len3[3] += len2[2];
            len2[1] += len1[0];
            len2[2] += len1[1];
            len1[1] ++;
        }
        rep(j,0,3)
            len1[j]%=M, len2[j]%=M, len3[j]%=M;
    }
    int ans=0;
    rep(i,0,3)
        if (len3[i]>0)
            ans = (ans+len3[i]*pp[tot-i])%M;
    cout << ans << '\n';
}