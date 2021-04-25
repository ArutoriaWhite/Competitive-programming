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

signed main()
{
    int T;
    cin >> T;
    while (T--)
    
    {
        string s;
        cin >> s;
        int tot=0;
        for (int i=0; i<s.size(); i++)
            tot += s[i]-'0';
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        if (s[s.size()-1] == '0' && tot%3==0)
            cout << s << '\n';
        else cout << -1 << '\n';
    }
}