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
const int N = 2e5+10;

int n, a[N];
priority_queue<int, vector<int>, less<int>> pq;
signed main()
{
    cin >> n;
    rep(i,1,n)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    rep(i,1,n)
        if (a[i]>0)
            pq.push(a[i]);
    if (pq.size()<=1) cout << 0 << '\n';
    else
    {
        pq.pop();
        int res=pq.top();
        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
        cout << res << '\n';
    }
}