#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int n;
string s;

inline int check (string &x)
{
    for (int i=0; i<n-1; i++)
    {
        if (s[i] == s[i+1])
            return 0;
    }
    return 1;
}

int main()
{
    int res = 0;
    cin >> n >> s;
    sort(s.begin(), s.end());www
    do{
        res += check(s);
    }while (next_permutation(s.begin(), s.end()));
    cout << res << '\n';
}4