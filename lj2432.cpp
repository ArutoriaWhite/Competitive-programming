#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1000;

int dp[N], m, n;
string s, dic[N];

signed main()
{
    cin >> m >> n;
    for (int i=1; i<=m; i++) cin >> dic[i];
    cin >> s;
    for (int i=s.size()-1; i>=0; i--)
    {
        dp[i] = 1e9;
    }
}