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

signed main()
{
    int n, owo=1, res=0;
    cin >> n;
    if (n < 0) owo=-1, n*=-1;
    while (n>0)
    {
        res *= 10;
        res += n%10;
        n/=10;
    }
    cout << res*owo << '\n';
}