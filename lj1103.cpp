#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define Eriri ios::sync_with_stdio(0), cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<int,int> Pii;
const int N = 110;

Pii a;
int n, k, dp[N][N];
/*
dp[i][j], end with i, took j books, = min dif sum
dp[i][j] = max(dp[k][j-1] + dif(i,k), j-1<=k<i)
*/
int main()
{

}