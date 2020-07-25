#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
#define int long long
using namespace std;
const int N = 3, M = 1e9+7;
typedef pair<int,int> Pii;
typedef int natori[N][N];
typedef int (*akagi)[N];

natori init =
{
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
};
natori swit = 
{
    {1, 1, 1},
    {1, 2, 1},
    {1, 1, 2}
};
natori a, b, c;

void print (akagi m)
{
    for (int y=0; y<N; y++)
    {
        for (int x=0; x<N; x++)
        {
            cout << m[y][x] << ' ';
        }
        cout << '\n';
    }
}

void mult (akagi s, akagi t, akagi res)
{
    for (int y=0; y<N; y++)
    {
        for (int x=0; x<N; x++)
        {
            res[y][x] = 0;
            for (int i=0; i<N; i++)
                res[y][x] = ((s[y][i] * t[i][x])%M + res[y][x])%M;
        }
    }
}
akagi qpow (int n)
{
    akagi res = a, k = b, tmp = c;
    res = init, k = swit;

    for ( ;n; n>>=1)
    {
        if (n&1)
        {
            mult(res, k, tmp);
            swap(tmp, res);
        }
        mult(k, k, tmp);
        swap(k, tmp);
    }
    return res;
}


signed main()
{
    int n;
    cin >> n;
    akagi m = qpow(n);
    cout << ((m[0][0] + m[1][0] )%M + m[2][0])%M << '\n';
}

/*
f[i][j]
j == 0 |
j == 1 \
j == 2 /

f[i][0] = f[i-1][0] + f[i-1][1] + f[i-1][2]
f[i][1] = f[i-1][0] + f[i-1][1] + f[i-1][2] + f[i-1][1]
f[i][2] = f[i-1][0] + f[i-1][1] + f[i-1][2] + f[i-1][2]

[1, 1, 1]
{f0, f1, f2} *
{
    1 1 1
    1 2 1 
    1 1 2
}
*/