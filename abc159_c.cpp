#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;

int a;

signed main()
{
    cin >> a;
    cout << fixed << setprecision(6) << (double)(a*a*a)/27 << '\n';
}