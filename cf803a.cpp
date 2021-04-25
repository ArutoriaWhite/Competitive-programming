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
1 1 1 1 
1 0 0 0
1 0 0 0
1 0 0 0
give n, k, construct a matrix n*n have exact k 1 and dui-cheng with main diagonal
answer the max lexicographically matrix

fill n*n always better
is there any other choice?
1. enouph to fill n*n out ring
    1. move two in to n-1, n-1 (X)
    2. move one in (X)
2. not enouph to fill n*n out ring
    fill max x such that x&1, x<=rest, x<=2*n-1

k = 7
0 0 0
0 0 0
0 0 0
1 1 0
1 1 0
0 0 0
*/
const int N = 110;
int n, k;
int a[N][N];

void fill (int i, int len, int rest)
{
    if (len <= 0 || rest<=0) return;
    int tf = min((rest&1? rest:rest-1), (len*2-1));
    rep(j,i,i+(tf+1)/2-1) a[i][j] = 1;
    rep(j,i,i+(tf+1)/2-1) a[j][i] = 1;    
    fill(i+1,len-1,rest-tf);
}

signed main()
{
    ShinraTensei
    cin >> n >> k;
    if (k > n*n)
    {
        cout << -1 << '\n';
        return 0;
    }
    fill(1,n,k);
    rep(i,1,n)
    {
        rep(j,1,n)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}