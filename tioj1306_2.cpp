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
const int N = 1e4+10;

string pat, s;
int f[N], T, Q; // f[i]; pat len i preffix, max length preffix == suffix

void build()
{
    f[0] = -1, f[1] = 0;
    for (int i=1,j=0; i<pat.size(); i++,j++,f[i]=j)
        while (j>=0 && pat[i]!=pat[j])
            j = f[j];
}
int kmp()
{
    int cnt = 0;
    for (int i=0,j=0; i<s.size(); i++,j++)
    {
        while (j>=0 && s[i]!=pat[j]) j = f[j];
        if (j == pat.size()-1) cnt++;
    }
    return cnt;
}

signed main()
{
    ShinraTensei
    cin >> T;
    while (T--)
    {
        cin >> s >> Q;
        while (Q--)
        {
            cin >> pat;
            build();
            cout << kmp() << '\n';
        }
    }
}