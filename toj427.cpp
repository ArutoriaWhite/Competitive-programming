#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e6+10;

int phi[N] = {1}, sv[N], pre[N];

signed main()
{
    Eriri
    for (int i=2; i*i<N; i++)
        for (int j=i+i; j<N; j+=i)
            sv[j] = (sv[j]? sv[j] : i);
    for (int i=1; i<N; i++)
        sv[i] = (sv[i]? sv[i] : i);
    for (int i=1,x; i<N; i++)
    {
        x = phi[i] = i;
        while (x!=1)
        {
            int y = sv[x];
            phi[i] = phi[i]*(y-1)/y;
            while (x%y == 0) x /= y;
        }
    }
    for (int i=1; i<N; i++)
        pre[i] = pre[i-1] + phi[i];
    int n;
    while (cin >> n)
    {
        if (n == 0) cout << 0 << '\n';
        else cout << 3 + (pre[n]-pre[1])*2 << '\n';
    }
}