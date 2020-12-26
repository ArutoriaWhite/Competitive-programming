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

map<char, int> mp;

signed main()
{
    XinAi
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++)
        mp[s[i]]++;
    if (mp.size() > 4 || mp.size()<2)
        cout << "No\n";
    else if (mp.size()==2)
    {
        int les2=0;
        for (auto kvp: mp)
            if (kvp.S<2) les2 = 1;
        cout << (les2? "No":"Yes") << '\n';
    }
    else if (mp.size()==3)
    {
        int greater1=0;
        for (auto kvp: mp)
        {
            if (kvp.S > 1) greater1 = 1;
        }
        cout << (greater1? "Yes":"No") << '\n';
    }
    else if (mp.size()==4)
    {
        cout << "Yes\n";
    }
}