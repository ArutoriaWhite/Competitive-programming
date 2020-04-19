#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 10;

int n, f[N][N][N][N], arr[N][N];

int main ()
{
    yukari;
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c && (a||b||c))
        arr[a][b] = c;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    if (i+j != k+l) continue;
                    f[i][j][k][l] = max( f[i-1][j][k-1][l],
                                    max( f[i][j-1][k-1][l],
                                    max( f[i-1][j][k][l-1],
                                         f[i][j-1][k][l-1] )));
                    if (i==k && j==l)
                        f[i][j][k][l] += arr[i][j];
                    else
                        f[i][j][k][l] += arr[i][j] + arr[k][l];
                }
            }
        }
    }
    cout << f[n][n][n][n] << '\n';
}

// dp[i][j] = max(dp[i-1][j])