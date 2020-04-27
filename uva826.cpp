#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 1e4;

int dp[N][N], a[N][N];
int mx, my, t, fir=1;
string s;
stringstream ss;

int main()
{


    Eriri
    cin >> t;
    while (t--)
    {
        if (fir) fir=0;
        else cout << '\n';
        
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        cin >> my >> mx;
        getline(cin,s);

        dp[mx][my] = 1, a[mx][my] = 1;
        for (int i=1,y,x; i<=my; i++)
        {
            getline(cin,s);
            ss.clear(), ss.str(s);
            ss >> y;
            while (ss >> x) a[x][y] = 1;
        }

        for (int y=my; y>0; y--)
            for (int x=mx; x>0; x--)
                if (!a[x][y])
                    dp[x][y] = dp[x+1][y] + dp[x][y+1];
        cout << dp[1][1] << '\n';
    }
}
/*
1
4 5
1
2 2
3 3 5
4
*/