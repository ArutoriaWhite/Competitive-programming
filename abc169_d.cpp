#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N = 1e13, M = sqrt(N)+10;

int np[M];

signed main()
{
    for (int i=2; i<M; i++)
        if (!np[i])
            for (int j=i*2; j<M; j+=i)
                np[j] = 1;
    int n, res=0;
    cin >> n;
    for (int i=2; i<M; i++)
    {
        if (np[i]) continue;
        if (n % i == 0)
        {
            int owo = 0;
            while (n%i == 0) n /= i, owo++;
            for (int j=1; owo-j>=0; owo-=j,j++,res++);
        }
    }
    if (n > 1) res++;
    cout << res << '\n';
}
