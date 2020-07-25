#include <bits/stdc++.h>
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
using namespace std;
typedef pair<int,int> Pii;

int dp[110][75][75][75], v[100], w[100], b[5];
int n, m;
int main()
{
    Eriri
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> b[i];
    cin >> m;
    for (int i=0; i<m; i++)
        cin >> w[i] >> v[i];
    for (int i=m-1; i>=0; i--){
        for (int p=0; p<=b[0]; p++) {
            for (int q=0; q<=b[1]; q++) {
                for (int r=0; r<=b[2]; r++) {
                    int &x = dp[i][p][q][r];
                    x = dp[(i+1)][p][q][r];
                    if (p >= w[i]) x = max(x, dp[(i+1)][p-w[i]][q][r]+v[i]);
                    if (q >= w[i]) x = max(x, dp[(i+1)][p][q-w[i]][r]+v[i]);
                    if (r >= w[i]) x = max(x, dp[(i+1)][p][q][r-w[i]]+v[i]);
                }
            }
        }
    }
    cout << dp[0][b[0]][b[1]][b[2]] << '\n';
}