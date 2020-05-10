#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1010;

struct Big
{
    int num[N];
    Big (int x)
    {
        memset(num,0,sizeof(num));
        for (int i=0; i<N; i++)
            num[i] = x%10, x/=10;
    }
    Big(){}
    Big operator+ (const Big &x)
    {
        int a=0;
        Big res{0};
        for (int i=0; i<N; i++)
        {
            res.num[i] = num[i] + x.num[i] + a;
            a = res.num[i]/10, res.num[i]%=10;
        }
        return res;
    }
    inline void print()
    {
        int f = 0;
        for (int i=N-1; i>=0; i--)
            if (f |= num[i]!=0) cout << num[i];
        if (f==0) cout << 0;
        cout << '\n';
    }
} dp[N];

int main()
{
    Eriri
    dp[0] = {1}, dp[1] = {2}, dp[2] = {5}, dp[3] = {13};
    for (int i=4; i<N; i++)
        dp[i] = dp[i-1] + dp[i-1] + dp[i-2] + dp[i-3];
    int n;
    while (cin >> n)
        dp[n].print();
}
/*
dp[u] = dp[u-1]+dp[u-1]+dp[u-2]+dp[u-3]
if (u==0) return 1
*/