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
const int N = 1e6+10;
/*
求 sqrt(n)~n 之間的質數的數量
*/
vector<int> primes;
int np[N];

signed main()
{
    exploootion
    for (int i=2; i<N; i++)
    {
        if (!np[i]) primes.eb(i);
        for (int j=i*i; j<N; j+=i)
            np[j] = 1;
    }
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        auto r = upper_bound(primes.begin(), primes.end(), n);
        auto l = upper_bound(primes.begin(), primes.end(), sqrt(n));
        cout << r-l+1 << '\n';
    }
}