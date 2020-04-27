#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 25, M = 210;

int dp[N][M][M], used[N][M][M], w[N];
int n, t, T;
string s;
stringstream ss;

int f (int i, int w1, int w2)
{
    if (i==n) return w1==w2;
    if (dp[i][w1][w2]==-1)
        dp[i][w1][w2] = f(i+1,w1+w[i],w2) || f(i+1,w1,w2+w[i]);
    return dp[i][w1][w2];
}

int main()
{
    Eriri
    cin >> T, getline(cin,s);
    while (T--)
    {
        getline(cin,s), ss.str(s), n=0;
        memset(dp,-1,sizeof(dp));
        while (ss>>w[n++]);
        cout << (f(0,0,0)? "YES":"NO") << '\n';
        ss.clear(), ss.str("");
    }
}