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

int i, res, n;
string s;

void sol (int k)
{
    int x = s[i++]-'0';
    if (x<2) 
        res += k*k*x;
    else
        sol(k/2), sol(k/2), sol(k/2), sol(k/2);
}

signed main()
{
    cin >> s >> n;
    sol(n);
    cout << res << '\n';
}