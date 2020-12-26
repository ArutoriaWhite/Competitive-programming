#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
const int N = 100000+10;

map<int,int> A, B;
int n, m, k, res;

signed main()
{
    cin >> m >> n >> k;
    rep(i,1,m)
    {
        int x;
        cin >> x;
        A[x]++;
    }
    rep(i,1,n)
    {
        int x;
        cin >> x;
        B[x]++;
    }
    for (auto x: A)
    {
        res += x.ss * B[k-x.ff];
    }
    cout << res << '\n';
}