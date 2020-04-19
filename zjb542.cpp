#pragma GCC optimize("Ofast,no-stack-protector")
#include <iostream>
#include <set>
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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 1e5+10;

set<int> apr;
int arr[N], n, q;

inline bool check (int x)
{
    for (int i=0; i<n; i++)
        if (exi(x+arr[i],apr) || exi(arr[i]-x,apr))
            return 1;
    return 0;
}

int main()
{
    yukari;
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> arr[i], apr.insert(arr[i]);
    for (int i=0,x; i<q; i++)
        cin >> x, cout << (check(x)? "YES" : "NO") << '\n';
}