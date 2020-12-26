#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define haaachamachama ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+10;

string s;
map<char,int> cnt;
char win[200];

signed main()
{
    win['R'] = 'P';
    win['S'] = 'R';
    win['P'] = 'S';
    haaachamachama
    int t;
    cin >> t;
    while (t--)
    {
        cnt.clear();
        cin >> s;
        for (auto c: s) cnt[c]++;
        int mx=0;
        char c;
        for (auto kvp: cnt)
        {
            if (kvp.ss>mx) c = kvp.ff, mx=kvp.ss;
        }
        rep(i,1,SZ(s)) cout << win[c];
        cout << '\n';
    }
}