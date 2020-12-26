#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e8;

bitset<N+10> np;
vector<int> p;

inline int rev (int i)
{
    int res=0;
    for (;i>0; i/=10) res=(res*10+i%10);
    return res;
}

signed main()
{
    XinAi
    np[0] = np[1] = 1;
    rep(i,2,N) if (!np[i]) for (int j=i*i; j<N; j+=i) np[j]=1;
    rep(i,2,N) if (!np[i]&&!np[rev(i)]&&i!=rev(i)) p.push_back(i);
    int t, n;
    cin >> t;
    while (t--)
        cin >> n, cout << p[n-1] << '\n';
}