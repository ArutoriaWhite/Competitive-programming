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
/*
give d, find min a such that:
a is not a prime
difference between any two divisors >= d

1, a, b, a*b
1, first prime greater than 1+d, first prime greater than lastp + d, 
the 20000th prime:
*/
const int N = 1e6+10;

int np[N];
vector<int> p;

signed main()
{
    rep(i,2,N-1)
    {
        if (!np[i]) p.pb(i);
        for (int j=i*i; j<N; j+=i)
            np[j] = 1;
    }
    int t, d;
    cin >> t;
    while (t--)
    {
        cin >> d;
        int a = *lower_bound(p.begin(), p.end(), 1+d);
        int b = *lower_bound(p.begin(), p.end(), a+d);
        cout << a*b << '\n';
    }
}