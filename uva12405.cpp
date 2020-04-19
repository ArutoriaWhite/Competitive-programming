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
const int INF=0x3f3f3f3f, MIN=0xc0c0c0c0, N = 110;

int arr[N], n, T, res;

int main ()
{
    yukari;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        res = 0;
        cin >> n;
        char c;
        for (int i=0; i<n; i++)
            cin >> c, arr[i] = c=='.';
        for (int i=0; i<n; i++)
            if (arr[i]) i+=2, res++;
        cout << "Case " << t << ": " << res << "\n";
    }
}