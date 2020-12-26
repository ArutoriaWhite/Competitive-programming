#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

int a, c;
string b;

signed main()
{
    cin >> a >> b;
    int res = 0;
    c += b[0]-'0', c*=10;
    c += b[2]-'0', c*=10;
    c += b[3]-'0';
    res = a * c / 100;
    cout << res << '\n';
}