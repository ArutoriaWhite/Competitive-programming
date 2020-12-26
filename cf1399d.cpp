#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    XinAi
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int id = 0;
        string ans;
        vector<int> v[2];
        for (int i=0,j=1; i<s.size(); i++,j++)
        {
            int x = s[i]-'0', y = !x;
            if (v[y].empty())
                v[x].push_back(++id);
            else
                v[x].push_back(v[y].back()), v[y].pop_back();
            ans += to_string(v[x].back()) + " ";
        }
        cout << id << '\n' << ans << '\n';
    }
}