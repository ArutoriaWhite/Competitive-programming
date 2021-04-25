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

string s = "0codeforces";
int k;
int qpow (int i, int j)
{
    int res=1;
    for (; j; j>>=1,i*=i)
        if (j&1) res *= i;
    return res;
}
int cando (int sum)
{
    int c1 = sum%10;
    int c2 = 10 - c1;
    int x = sum/10;
    int res = qpow(x+1,c1) * qpow(x,c2);
    if (res >= k)
    {
        rep(i,1,c1)
            rep(j,1,x+1) cout << s[i];
        rep(i,c1+1,10)
            rep(j,1,x) cout << s[i];
        return 0;
    }
    return 1;
}

signed main()
{
   cin >> k;
   int i=1;
   while (cando(i)) i++;
}
