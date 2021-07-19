#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define pui ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    rep(i,1,1e9)
    {
        if ((i*i)%1800 == 1609)
        {
            cout << i << endl;
            exit(0);
        }
    }
}