#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define SakuraMyWife ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int N = 210;

int n, owo;
int dp2[N][N][N]; // 1~i, j replacement can use, k 
int dp[N][N][N]; //1~i, j replacement can use, k fw, max t
char fw, bw, s[N];

signed main()
{
    cin >> n >> owo;
    rep(i,1,n) cin >> s[i];
    cin >> fw >> bw;
    rep(i,1,n)
    {
        rep(j,0,owo)
        {
            rep(k,0,n) 
            {
                if (s[i]==fw)
                {
                    
                }
                if (s[i]==bw)
                {

                }
                if (k>0)
                {

                }
                //to fw
                // to bw
                // no change
            }
        }
    }
}