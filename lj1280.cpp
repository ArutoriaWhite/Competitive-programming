#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4+10;

int n, k, f[N];
Pii t[N];
vector<int> v[N];

int main()
{
    Eriri
    cin >> n >> k;
    for (int i=1; i<=k; i++)
    {
        cin >> t[i].F >> t[i].S;
        t[i].S += t[i].F-1;
        v[t[i].F].push_back(i);
    }
    for (int i=n; i>0; i--)
    {
        if (!v[i].size())
            f[i] = f[i+1]+1;
        else for (auto j: v[i])
            f[i] = max( f[i], f[t[j].S+1]);
    }
    cout << f[1] << '\n';
}