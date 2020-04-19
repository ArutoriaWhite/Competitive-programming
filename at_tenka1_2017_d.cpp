#include <bits/stdc++.h>
#define yukari ios::sync_with_stdio(0), cin.tie(0)
#define de(x) cout << #x << "=" << x << ", "
#define dend cout << '\n'
#define lowbit(x) (x&-x)
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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e5+10;

int n, k, a[N], b[N], res;
 
int main()
{
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> a[i] >> b[i];
    for (int x=k,t=0; x>0; x&=~(t-1))
    {
        t = lowbit(x), x--;
        int sum = 0;
        for (int i=0; i<n; i++)
            if ((x|a[i]) == x) sum += b[i];
        res = max(res, sum);
    }
    cout << res << '\n';
}
