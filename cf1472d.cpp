#include <bits/stdc++.h>
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define ShinraTensei ios::sync_with_stdio(0), cin.tie(0);
#define ff first
#define ss second
#define int long long
#define SZ(x) ((int)x.size())
#define pb push_back
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;
/*
giving an array x (n < 2e5, x[i] < 1e9)
alice can remove an element from x, if it is even, she adds it to her score
bob can remove an element from x, if it is odd, he adds it to his score

alice play first, who will win if they both play optimally?

categorize numbers with odd or even then sort them decreasingly

ascore[i][j] // max number alice can gain
bscore // max number bob can gain

bstole[i][j] // in the case of b gaing the max score, how much odd will he take
bstole[i][j] = how_much_b_take(i,j) - bscore(i,j)

ascore[i][j] =
max
{
    odd_sum[i] - bsum(i-1,j) + bscore(i-1,j), -> asum(i,j) = asum(i-1,j) + odd[i]
    odd_sum[i] - bsum(i,j-1) + bscore(i,j-1), -> asum(i,j) = asum(i,j-1) + even[j];
}

dpa(i,j) // how much will a's score greate than b'score
dpa(i,j) = 
max(evne[i]+dpa(i,j+1), a[i]+dpa(i+1,j))

*/