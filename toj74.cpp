#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

string s;
int n;

inline bool can (int k)
{
    if ((n-k)%k!=0) return 0;
    if (n==k) return 1;
    for (int i=0,j=k; j<n; i=(i+1)%k,j++)
        if (s[i]!=s[j]) return 0;
    return 1;
}

int main()
{
    Eriri
    cin >> s, n = s.size();
    for (int i=1; i<=n; i++)
    {
        if (can(i))
        {
            for (int j=0; j<i; j++) cout << s[j];
            cout << '\n';
            break;
        }
    }
}