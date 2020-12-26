#include <bits/stdc++.h>
#define de(x) cout << #x << '=' << x << ", "
#define dd cout << '\n';
#define XinAi ios::sync_with_stdio(0), cin.tie(0);
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define S second
#define F first
#define SZ(x) ((int)x.size())
#define int long long
using namespace std;
typedef pair<int,int> pii;

/*
dp[i][t] = 1~i, t cap, max val
dp[i][t] = max( dp[i-1][t - k*w[i]] + k*m[i] , k=1~c[i])
t greater, dp[i][t] greater

t1%c[i] === t2%c[i] = r
dp[i][t1] = max{dp[i-1][r+k*w[i]] + (t1/w[i]-k)*m[i] | k=0~t1/w[i]}
dp[i][t2] = max{dp[i-1][r+k*w[i]] + (t2/w[i]-k)*m[i] | k=0~t2/w[i]}
k greater, dp[i][t] greater
Q greater, dp greater
t greater, dp greater


vector<int> C[i];
*/
