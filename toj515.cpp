#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
typedef long long LL;

int n;

inline bool check (int x)
{
    for (int i=1; i<=9; i++)
        if (x == i*1111) return 1;
    return 0;
}

int main()
{
    cin >> n;
    cout << (check(n)? "GREAT!!":"OAQ") << '\n';
}