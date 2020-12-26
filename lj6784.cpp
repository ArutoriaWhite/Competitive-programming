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
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef pair<int,int> pii;

signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a>b) swap(a,b);
    
    if (a+c <= b)
        a += c;
    else
    {
        c -= b-a;
        a = b;
        a += c/2;
    }
    rep(i,1,1e7)
    {
        if (a >= i) a -= i;
        else
        {
            cout << i-1 << '\n';
            break;
        }    
    }
}