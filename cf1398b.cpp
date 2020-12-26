#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

string s;
priority_queue<int, vector<int>, less<int>> pq;

signed main()
{
    XinAi;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s, s += "0";
        int cnt = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (s[i] == '1') cnt++;
            else if (cnt > 0)
            {
                pq.push(cnt);
                cnt = 0;
            }
        }
        int i = 1, res = 0;
        while (!pq.empty())
        {
            res += pq.top() * (i&1);
            pq.pop();
            i++;
        }
        cout << res << '\n';
    }
}