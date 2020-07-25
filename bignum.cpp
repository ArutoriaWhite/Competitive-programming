#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1000;

struct Big
{
    int n[N];
    Big (string s)
    {
        memset(n,0,sizeof(n));
        for (int i=0,j=s.size()-1; j>=0; i++,j--)
            n[i] = s[j]-'0';
    }
    inline Big operator + (Big x)
    {
        Big res = {"0"};
        int a = 0;
        for (int i=0; i<N; i++)
        {
            res.n[i] = n[i]+x.n[i]+a;
            a = res.n[i]/10, res.n[i]%=10;
        }
        return res;
    }
    inline Big operator * (Big x)
    {
        Big res = {"0"};
        for (int j=0; j<N; j++)
        {
            for (int i=0; i<N; i++)
            {
                if (i+j >= N) continue;
                res.n[i+j] += n[i] * x.n[j];
            }
        }
        int a = 0;
        for (int i=0; i<N; i++)
        {
            res.n[i] += a;
            a = res.n[i]/10;
            res.n[i] %= 10;
        }
        return res;
    }
    inline void print ()
    {
        int flag = 0;
        for (int i=N-1; i>=0; i--)
        {
            flag |= n[i]!=0;
            if (flag) cout << n[i];
        }
        cout << '\n';
    }
};

int main()
{
    Big a = {"123"}, b = {"456"};
    a.print();
    b.print();
    (a+b).print();
    (a*b).print();
}