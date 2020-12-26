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

string s;
vector<char> v;
int cnt[200];
int t, n;

signed main()
{
    ShinraTensei
    cin >> t;
    while (t--)
    {
        mem(cnt,0);
        v.clear();
        cin >> n >> s;
        for (int i=0; i<n; i++)
        {
            if (s[i]=='t'||s[i]=='r'||s[i]=='y'||s[i]=='g'||s[i]=='u'||s[i]=='b')
            {
                cnt[s[i]]++;
            }
            else
            {
                v.pb(s[i]);
            }
        }
        for (auto c: v) cout << c;
        string x = "bugyrt";
        for (int i=0; i<6; i++)
        {
            for (int j=0; j<cnt[x[i]]; j++)
            {
                cout << x[i];
            }
        }
        cout << '\n';
    }
}