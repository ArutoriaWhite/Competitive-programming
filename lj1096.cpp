#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
typedef pair<int,int> Pii;
const int N = 500;

int n;

struct bignum
{
    int num[100], M = 100;
    inline void init()
    {
        memset(num,0,sizeof(num));
    }
    inline void mul2()
    {
        int a = 0;
        for (int i=0; i<M; i++)
            num[i]=num[i]*2+a, a=num[i]/10, num[i]%=10;
    }
    inline void add1()
    {
        int a = 1;
        for (int i=0; i<M; i++)
            num[i]+=a, a=num[i]/10, num[i]%=10;
    }
    inline void print()
    {
        bool f=0;
        for (int i=M-1; i>=0; i--)
        {
            f |= (num[i]!=0);
            if (f) cout << num[i];
        }
        cout << '\n';
    }
};

signed main()
{
    cin >> n;
    bignum x;
    x.init();
    for (int i=1; i<=n; i++)
        x.mul2(), x.add1();
    x.mul2();
    x.print();
}