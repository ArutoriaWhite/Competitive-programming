#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e5+10;

int cnt[N];
int e, f, t, s;
void add (int x)
{
    cnt[x]++;
    if (cnt[x] == 8) e++, s--;
    else if (cnt[x] == 6) s++, f--;
    else if (cnt[x] == 4) f++, t--;
    else if (cnt[x] == 2) t++;
}
void del (int x)
{
    if (cnt[x] == 8) e--, s++;
    else if (cnt[x] == 6) s--, f++;
    else if (cnt[x] == 4) f--, t++;
    else if (cnt[x] == 2) t--;
    cnt[x]--;
}

signed main()
{
    XinAi
    int n;
    cin >> n;
    for (int i=0,x; i<n; i++)
        cin >> x, add(x);
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') add(x);
        else del(x);
        if (e>=1 || s>=2 || (s>=1&&(f>=1||t>=1)) || (f>=2) || (f>=1 && t>=2))
            cout << "YES\n";
        else cout << "NO\n";
    }
}
