#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 70;

int f[N][N], n, k;

signed main()
{
    f[1][1] = 1;
    for (int i=2; i<=N; i++)
        for (int j=1; j<=i; j++)
            f[i][j] = f[i-1][j] + f[i-1][j-1];
    cin >> k >> n;
    for (int i=k+1, b=n-k-1; i<=n; i++,b--)
    {
        for (int j=1; j<=b; j++)
            cout << ' ';
        for (int j=1; j<=i; j++)
            cout << f[i][j] << ' ';
        cout << '\n';
    }
}