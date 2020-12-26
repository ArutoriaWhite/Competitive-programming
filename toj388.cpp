#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

string hex, ith="0123456789abcdef";
char hti[200];
vector<int> bin;
set<int> ans;

signed main()
{
    rep(i,0,15) hti[ith[i]]=i;
    string s;
    cin >> s;
    for (int i=s.size()-1; i>=0; i--)
    {
        int x = hti[s[i]];
        for (int j=0; j<4; j++,x>>=1)
        {
            bin.push_back(x&1);
        }
    }
    vector<int> pos;
    for (int i=0; i<bin.size(); i++)
        if (bin[i]) pos.push_back(i);
    for (int i=1; i<pos.size()-1; i++)
        if (pos[i]-pos[i-1] == pos[i+1]-pos[i] && pos[i]%(pos[i]-pos[i-1])==0)
            ans.insert(pos[i] - pos[i-1]);
    for (auto i: ans) cout << i << '\n';
}
