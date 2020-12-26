#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_h with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

string s;

void calc (int n, int &x, int &y)
{
    for (int i=0; i<n; i++)
    {
        if (s[i]=='W') x--;
        if (s[i]=='E') x++;
        if (s[i]=='S') y--;
        if (s[i]=='N') y++;
    }
}

signed main()
{
    int t;
    cin >> s >> t;
    int x=0, y=0;
    calc(SZ(s), x, y);
    x *= t/SZ(s), y *= t/SZ(s);
    calc(t%SZ(s), x, y);
    cout << x << ' ' << y << '\n';
}