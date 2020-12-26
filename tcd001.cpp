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

vector<int> st;

signed main()
{
    ShinraTensei
    string s, in;
    stringstream ss;
    getline(cin,s);
    reverse(s.begin(), s.end());
    ss.str(s);
    while (ss >> in)
    {
        if (in[0]=='f')
        {
            int x = st.back();
            st.pop_back();
            st.pb(2*x-1);
        }
        else if (in[0]=='g')
        {
            int x = st.back(); st.pop_back();
            int y = st.back(); st.pop_back();
            st.pb(x+2*y-3);
        }
        else
        {
            reverse(in.begin(), in.end());
            st.pb(atoi(in.c_str()));
        }
    }
    cout << st.back() << '\n';
}