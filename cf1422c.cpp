#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define exploootion ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define eb emplace_back
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+10, M=1e9+7;

string s;
int n, a[N], pre[N];

signed main()
{
    cin >> s;
    n = SZ(s);
    for (int i=0; i<n; i++)
    {
        a[i] = s[i]-'0';
    }
    int sum=0;
    for (int i=n-1,t=1,j=1; i>0; i--,t=(t*10)%M,j++)
        sum = (sum+(i+1)*i/2%M*a[i]%M*t%M)%M;
    for (int i=1; i<n; i++)
    {
        pre[i] = (pre[i-1]+a[i-1])%M;
    }
    for (int i=n-1,t=1; i>0; i--,t=(t*10)%M)
    {
        sum = (sum+pre[i]*(n-i)%M*t%M)%M;
    }
    cout << sum << '\n';
}