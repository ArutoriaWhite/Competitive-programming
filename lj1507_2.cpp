#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define MegumiMyWife ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 50, M = 400;

int dp[M][M], n, maxV, maxW, vi[N], wi[N], ci[N];
// dp[i][v][w] = max(dp[i+1][v][w], dp[i+1][v-vi[i]][w-wi[i]]+ci[i])
int main()
{
    cin >> maxV >> maxW >> n;
    for (int i=0; i<n; i++)
        cin >> vi[i] >> wi[i] >> ci[i];
    for (int i=n-1; i>=0; i--)
    {
        for (int v=maxV; v>=0; v--)
        {
            for (int w=maxW; w>=0; w--)
            {
                if (v>=vi[i] && w>=wi[i])
                    dp[v][w] = max( dp[v][w], dp[v-vi[i]][w-wi[i]]+ci[i] );
            }
        }
    }
    cout << dp[maxV][maxW] << '\n';
}