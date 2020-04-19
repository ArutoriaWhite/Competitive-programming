#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define mem(a,x) memset(a,x,sizeof(a))
#define exi(x,s) (s.find(x)!=s.end())
#define Uset unordered_set
#define Umap unordered_map
#define Pq priority_queue
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e6+10;

Pq<ll,vector<ll>,greater<ll>> pq;
int res, n;

int main()
{
    yukari;
    while (cin >> n && n)
    {
        while (!pq.empty()) pq.pop();
        res = 0;
        for (int i=0,x; i<n; i++)
            cin >> x, pq.push(x);
        for (int i=0; i<n-1; i++)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            res += x+y;
            pq.push(x+y);
        }
        cout << res << '\n';
    }
}