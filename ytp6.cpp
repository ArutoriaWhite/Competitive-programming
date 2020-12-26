#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int t;
string s;
int k, pre[1000010];

signed main()
{
    Eriri
    cin >> t;
    while (t--)
    {
        cin >> s >> k;
        for (int i=0; i<s.size(); i++)
            pre[i] = 0;
        int res = 0;
        for (int i=0; i<s.size(); i++)
        {
            if (i > 0) pre[i] += pre[i-1];
            if ((s[i]=='O' && pre[i]&1) || (s[i]=='X' && !(pre[i]&1)))
            {
                if (i+k-1 > s.size()-1)
                {
                    res = -1;
                    break;
                }
                res++;
                pre[i]++;
                pre[i+k]--;
            }
        }
        cout << res << '\n';
    }
}