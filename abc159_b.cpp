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

inline int ispa (int l, int r)
{
    for (l--,r--; l<r; l++, r--)
        if (s[l] != s[r]) return 0;
    return 1;
}

signed main()
{
    cin >> s;
    int n = s.size();
    cout << (ispa(1,n) && ispa(1, (n-1)/2) && ispa((n+3)/2, n)? "Yes" : "No") << '\n';
}
