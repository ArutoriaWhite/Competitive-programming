#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long 
using namespace std;
typedef pair<int,int> Pii;
const int N = 5e4+10;

int n, k, p[N];

inline bool suc (int r)
{
    int cnt = 0, x=0;
    for (int i=0; i<n; i++)
        if (p[i] > x) x = p[i]+r*2, cnt++;
    return cnt<=k;
}

inline int bs()
{
    int i=0, s=1e9;
    while (s>0)
    {
        if (suc(i+s)) s>>=1;
        else i += s;
    }
    return (i+1)*2;
}

signed main()
{
    Eriri
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> p[i], p[i]*=2;
    sort(p,p+n);
    cout << bs()/2 << '\n';
}
