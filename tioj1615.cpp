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
const int N = 2e6;

int np[N];

signed main()
{
    for (int i=2; i<N; i++)
        if (!np[i])
            for (int j=i*i; j<N; j+=i) np[j] = 1;
    int a, b;
    while (cin >> a >> b)
    {
        if (a > b) swap(a, b);
        int res = 0;
        rep(i, 2, a) res += !np[i];

        int owo = 1;
        rep(i, a+1, b) owo *= i;
        owo++;

        rep(i, 2, N-1)
        {
            if (!np[i] && owo%i==0)
            {
                if (i>a) res++;
                while (owo%i==0) owo /= i;
            }
        }
        res += owo!=1;
        cout << res << '\n';
    }
}