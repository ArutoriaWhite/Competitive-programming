#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 30;
int c[N][N];

int fac (int x)
{
    int res=1;
    rep(i,1,x) res *= i;
    return res;
}

signed main()
{
    rep(i,0,N-1) c[i][0] = 1;
    rep(i,1,N-1)
        rep(j,1,N-1)
            c[i][j] = c[i-1][j-1]+c[i-1][j];
    int n, k;
    cin >> n;
    k = n/2;
    cout << c[n][k] * fac(k-1) *fac(k-1) /2;
}