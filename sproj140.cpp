#include<iostream>
using namespace std;
const int N=1e5+10, M=1000007, R=0, B=1, G=2;

int dp[N][3][3], n;

inline void init()
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (!((i==B&&j==G) || (i==G)&&(j==B)))
                dp[0][i][j] = 1;
    n = 1;
}
inline int f (int q)
{
    while (n<=q)
    {
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                for (int k=0; k<3; k++)
                    if (!((i==B&&k==G) || (i==G)&&(k==B)))
                        dp[n][i][j] = (dp[n][i][j]+dp[n-1][k][j])%M;
        n++;
    }
    return ((dp[q][R][R]+dp[q][B][B])%M+dp[q][G][G])%M;
}

int main()
{
    init();
    int T, x;
    cin >> T;
    while (T--)
    {
        cin >> x;
        cout << f(x-1) << '\n';
    }
}