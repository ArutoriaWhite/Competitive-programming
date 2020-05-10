#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define ton(c) (c-'0')
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;

string a;
LL b, n;

inline bool all_zero()
{
    for (int i=0; i<n; i++)
        if (a[i]!='-' && a[i]!='0') return 0;
    return 1;
}

inline bool check ()
{
    if (all_zero()) return 1;
    if (b==0) return 0;
    LL s = 0, t=1;
    for (int i=n-1; i>=0; i--,t=t*10%b)
        if (a[i] != '-')
            s = ( s + (ton(a[i])*t)%b )%b;
    return s==0;
}

int main()
{
    cin >> a >> b, n = a.size();
    if (check()) cout << "Yes\n";
    else cout << "No\n";
}
/*
-115062172 -28765543

206248266 14880787
*/