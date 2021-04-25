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
const int N = 2e5+10;

int a[N];

signed main()
{
    int n;
    cin >> n;
    rep(i,1,n) cin >> a[i];
    int cost = 0;
    rep(i,2,n)
    {
        int owo = max(a[i-1], a[i]);
        cost += owo - a[i];
        a[i] = owo;
    }
    cout << cost << '\n';
}