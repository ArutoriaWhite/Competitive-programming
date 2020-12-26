#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    int a, b, c, a2, b2, c2;
    char _;
    cin >> a >> _ >> b >> _ >> c >> a2 >> _ >> b2 >> _ >> c2;
    if (c2 < c) c2 += 60, b2 -= 1;
    if (b2 < b) b2 += 60, a2 -= 1;
    if (a2 < a) a2 += 24;
    cout << setw(2) << setfill('0') << a2-a << ':' << setw(2) << b2-b << ':' << setw(2) << c2-c << '\n';
}