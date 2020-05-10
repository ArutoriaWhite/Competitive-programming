#include <bits/stdc++.h>
using namespace std;

string s;
int n, t;

inline bool ispal(int l, int r, int d)
{
    if (d>1) return 0;
    if (r-l<=1) return 1;
    if (s[l]==s[r-1]) return ispal(l+1,r-1,d);
    else return ispal(l+1,r,d+1) || ispal(l,r-1,d+1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s, n = s.size();
        cout << (ispal(0,n,0)? "YES" : "NO") << '\n';
    }
}