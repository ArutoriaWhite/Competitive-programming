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
const int N = 2e5+10, A = 8;

int n, t;
vector<pii> steps;

int cdiv (int i, int j){ return i/j + ((i%j)>0);}

signed main()
{
    cin >> t;
    while (t--)
    {
        steps.clear();
        cin >> n;
        for (int i=n-1; i>2; i--)
        {
            if (i==A) continue;
            steps.pb({i,n});
        }
        int x;
        if (n > A)
        {
            x = n;
            while (x > 1)
            {
                steps.pb({n,A});
                x = cdiv(x,A);
            }
            steps.pb({A,2});
            steps.pb({A,2});
            steps.pb({A,2});
        }
        else
        {
            x = n;
            while (x > 1)
            {
                steps.pb({n,2});
                x = cdiv(x,2);
            }            
        }
        cout << steps.size() << '\n';
        for (auto p:steps) cout << p.ff << ' ' << p.ss << '\n';
    }
}

