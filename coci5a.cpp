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
set<string> st;

signed main()
{
    cin >> s;
    s += 'a';

    string x;
    for (int i=0; i<s.size(); i++)
    {
        if ('0'<=s[i] && s[i]<='9')
        {
            x += s[i];
        }
        else if ('0'<=s[i-1] && s[i-1]<='9')
        {
            st.insert(x);
            x = "";
        }
    }
    cout << st.size() << '\n';
}