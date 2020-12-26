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
int res = 0;

signed main()
{
    cin >> s;
    for (int i=0; i<s.size(); i++)
    {
        res += s[i] - '0';
        res %= 9;
    }
    cout << (res==0? "Yes" : "No") << '\n';
}
