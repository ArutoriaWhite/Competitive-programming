#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;

int main()
{
    long long a = 2;
    for (int i=0; i<25; i++)
    {
        a *=2, a+=1;
    }
    cout << a << '\n';
}