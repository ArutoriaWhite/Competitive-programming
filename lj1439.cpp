#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e5+10;

vector<int> dp;
int pos[N], a[N], n;

int main()
{
    Eriri  
    cin >> n;
    for (int i=1,x; i<=n; i++)
        cin >> x, pos[x] = i;
    for (int i=1,x; i<=n; i++)
        cin >> x, a[i] = pos[x];
    for (int i=1; i<=n; i++)
    {
        if (i==1 || dp.back()<a[i])
            dp.push_back(a[i]);
        else
            *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
    }
    cout << dp.size() << '\n';
}