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
const int N = 3e5+10;

int n, k, a[N], t;
string s;

int p[N];
int find (int x){ return (p[x]==x? x : p[x]=find(p[x])); }
inline void connect()
{
    for (int i=0; i<=n+2; i++) p[i] = i;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='0') p[find(i)] = find(n+1);
        else if (s[i]=='1') p[find(i)] = find(n+2);
    }
    for (int i=0; i+k<n; i++)
        p[find(i)] = find(i+k);
}

signed main()
{
    XinAi
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;
        connect();
        if (find(n+1)==find(n+2))
        {
            cout << "NO\n";
            continue;
        }
        int x=0, y=0;
        for (int i=0; i<k; i++)
        {
            if (find(i)==find(n+1)) x++;
            else if (find(i)==find(n+2)) y++;
        }
        if (x>k/2 || y>k/2) cout << "NO\n";
        else cout << "YES\n";
    }
}